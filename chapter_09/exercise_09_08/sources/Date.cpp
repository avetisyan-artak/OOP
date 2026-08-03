#include "headers/Date.hpp"
#include <iostream>
#include <cassert>

Date::Date()
{
    setMonth(1);
    setDay(1);
    setYear(2000);
}

Date::Date(const int month, const int day, const int year)
{
    setMonth(month);
    setDay(day);
    setYear(year);
}

Date::Date(const Date& rhv)
{
    setMonth(rhv.getMonth());
    setDay(rhv.getDay());
    setYear(rhv.getYear());
}

void
Date::setMonth(int month)
{
    assert(month > 0 && month < 13);
    month_ = month;
}

void
Date::setDay(int day)
{
    assert(day > 0 && day < 32);
    day_ = day;
}

void
Date::setYear(int year)
{
    assert(year > 0);
    year_ = year;
}

int
Date::getMonth() const
{
    return month_;
}

int
Date::getDay() const
{
    return day_;
}

int
Date::getYear() const
{
    return year_;
}

void
Date::nextDay()
{
    ++day_;

    if (MAX_DAY < day_) {
        day_ = 1;
        ++month_;
    }

    if (MAX_MONTH < month_) {
        month_ = 1;
        ++year_;
    }
}

void
Date::print() const
{
    std::cout << day_ << ":" << month_ << ":" << year_ << std::endl;
}

