#ifndef CSVMAP_H
#define CSVMAP_H

#include <iostream>
#include <map>
#include <stdlib.h>
#include <iomanip>
#include <fstream>
#include <vector>
#include <sstream>
#include "Date.h"

using namespace std;

class CSVMap
{
    public:
        CSVMap(const string& file_path, bool& header);
        virtual ~CSVMap();
        void DisplayDataFromDate(int month, int day, int year);
    private:
        map<Date, vector< string > > csvmap_;
        string file_path_;
        bool header_;
        vector<string> headers_;
        void ConstructMap();
};

#endif
