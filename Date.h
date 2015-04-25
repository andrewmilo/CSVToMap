#ifndef DATE_H
#define DATE_H

#include <iostream>
using namespace std;

class Date
{
    public:
        Date(int month, int day, int year);
        int getMonth();
        int getDay();
        int getYear();
        virtual ~Date();
        bool operator==(const Date&);
        bool operator!=(const Date&);
        bool operator< (const Date&) const;
        friend ostream& operator<<(ostream& os, const Date& dt);
    private:
        int month_;
        int day_;
        int year_;
};

#endif
