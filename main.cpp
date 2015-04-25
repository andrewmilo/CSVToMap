//BY ANDREW MILOSLAVSKY
//CSCI 335

#include <iostream>

#include <cstdio>
#include "Date.h"
#include "CSVMap.h"

using namespace std;

int main()
{
    string filepath;
    cout << "Enter the CSV file path: ";
    cin >> filepath;
    cout << endl;
    cout << "Does the CSV file contain a header? <Y/N> ";
    char header;
    cin >> header;
    cout << endl;

    bool hasHeader = false;

    if(tolower(header) == 'y')
        hasHeader = true;

    CSVMap mapdata(filepath, hasHeader);

    string date_string;
    cout << "Enter month, day, and year (M/D/YYYY): ";
    cin >> date_string;

    istringstream ss (date_string);

    int string_date[3];
    string splitdate;
    int count = 0;
    while(getline(ss, splitdate, '/'))
    {
        string_date[count] = atoi(splitdate.c_str());
        count++;
    }

    mapdata.DisplayDataFromDate(string_date[0], string_date[1], string_date[2]);

    return 0;
}
