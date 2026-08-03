#ifndef __DATE_AND_TIME__
#define __DATE_AND_TIME__

#include <iostream>
#include <iomanip>
#include <cassert>
#include <ctime>

const int MONTH_COUNT = 12;
const int MAX_HOUR = 24;
const int MAX_MINUTES = 60;
const int MAX_SECONDS = 60;
const int MIN_YEAR = 1900;
const int MAX_YEAR = 2100;
const int MAX_DAY = 31;
const int HALF_DAY = 12;
const int SPACE_SIZE = 2;

class DateAndTime
{
public:
    DateAndTime();
    DateAndTime(const int year, const int month, const int day,
                const int hour, const int minute, const int second);
    void setHours(const int hour);
    int getHours() const;
    void setMinutes(const int minute);
    int getMinutes() const;
    void setSeconds(const int second);
    int getSeconds() const;
    void setYear(const int year);
    int getYear() const;
    void setMonth(const int month);
    int getMonth() const;
    void setDay(const int day);
    int getDay() const;
    void tick();
    void nextDay();
    void printUniversal() const;
    void printStandard() const;
    void printDate() const;
    void printDateAndTime() const;

private:
    bool isLeapYear(const int year) const;
    int getDaysInMonth(const int year, const int month) const;
    bool isNextDay();
private:
    int year_;
    int month_;
    int day_;
    int hour_;
    int minute_;
    int second_;

};

#endif /// __DATE_AND_TIME_

