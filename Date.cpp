#include "Date.h"

Date::Date(int month, int day, int year)
{
    month_ = month;
    day_ = day;
    year_ = year;
}

Date::~Date()
{
}

bool Date::operator==(const Date& other)
{
    if(this->month_ == other.month_ && this->day_ == other.day_ && this->year_ == other.year_)
        return true;

    return false;
}

bool Date::operator!=(const Date& other)
{
    return !(*this == other);
}

bool Date::operator< (const Date &other) const
{
	if(this->year_ < other.year_)
		return true;
	else if(this->year_ > other.year_)
		return false;
	else
	{
		if(this->month_ < other.month_)
			return true;
		else if(this->month_ > other.month_)
			return false;
		else
		{
			if(this->day_ < other.day_)
				return true;
			else
				return false;
		}
	}
}

ostream& operator<<(ostream& os, const Date& dt)
{
    os << dt.month_ << '/' << dt.day_ << '/' << dt.year_;
    return os;
}

int Date::getMonth()
{
    return this->month_;
}

int Date::getDay()
{
    return this->day_;
}

int Date::getYear()
{
    return this->year_;
}
