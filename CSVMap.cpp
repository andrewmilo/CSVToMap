#include "CSVMap.h"

CSVMap::CSVMap(const string &file_path, bool& header)
{
    this->file_path_ = file_path;
    this->header_ = header;
    ConstructMap();
}

CSVMap::~CSVMap(){}

void CSVMap::ConstructMap()
{
    ifstream csvFile;
    csvFile.open(file_path_.c_str());

    if(csvFile.is_open())
    {
        string line;

        istringstream s(line);

        if(this->header_)
        {
            string header;

            //Record and skip header
            if(getline(csvFile, line))
            {
                istringstream ss(line);

                while(getline(ss, header, ','))
                    this->headers_.push_back(header);
            }
        }

        while(getline(csvFile, line))
        {
            istringstream ss(line);

            string column;
            Date* key_date = NULL;
            while(getline(ss, column, ','))
            {
                if(key_date == NULL)
                {
                    int string_date[3];
                    string splitdate;
                    int count = 0;
                    istringstream ss2(column);

                    while(getline(ss2, splitdate, '/'))
                    {
                        string_date[count] = atoi(splitdate.c_str());
                        count++;
                    }

                    key_date = new Date(string_date[0], string_date[1], string_date[2]);
                }
                else
                    this->csvmap_[*key_date].push_back(column);
            }

            delete key_date;
        }
    }
    else
        cout << "File not found.\n";

    csvFile.close();
}

void CSVMap::DisplayDataFromDate(int month, int day, int year)
{
    Date temp_date (month, day, year);

    cout << endl;

    for(int i = 0; i < this->headers_.size(); i++)
        cout << this->headers_[i] << ' ';

    cout << endl;
    cout << temp_date << ' ';
    for(int i = 0; i < this->csvmap_[temp_date].size(); i++)
        cout << this->csvmap_[temp_date][i] << ' ';

    cout << endl;
}
