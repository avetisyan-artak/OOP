#ifndef __DATE_HPP__
#define __DATE_HPP__

#include <string>

enum Format { ERROR, FORMAT_1, FORMAT_2, FORMAT_3 };

const int MONTH_COUNT = 12;
const int MIN_YEAR = 1900;
const int MAX_YEAR = 2100;
const int MAX_DAY = 31;
const int SIZE = 100;
const int POWER = 10;

static const int MIN_DAY = 1;
static const int MIN_MONTH = 1;
static const int MAX_MONTH = 12;
static const int FEB_MONTH = 2;
static const int FEB_DAYS_LEAP = 29;
static const int LEAP_YEAR_DIV_BY_4 = 4;
static const int LEAP_YEAR_DIV_BY_100 = 100;
static const int LEAP_YEAR_DIV_BY_400 = 400;

class Date
{
public:
    static bool isRightFormat(const char* dateName);
    Format getFormat(const char* dateName);

private:
    static void extractLetters(const char* dateName, char* month);
    static bool isRightFormat1(const char* dateName);
    static bool isRightFormat2(const char* dateName);
    static bool isRightFormat3(const char* dateName);
    static bool isDigit(const int start, const int end, const char* dateName);
    static int getMonthInNumber(const char* monthName);

public:
    Date();
    Date(const int year, const int month, const int day);
    Date(const int days, const int year);
    Date(const std::string& monthName, const int day, const int year);
    Date(const char* dateName);
    Date(const Date& rhv);

    void setYear(const int year);
    void setDay(const int day);
    int getDay() const;

    int getYear() const;
    void setMonth(const int month);
    int getMonth() const;

    void printNumeric() const;
    void printTextual() const;
    void printLong() const;
    void nextDay();
    int getDayOfYear() const;

private:
    bool isLeapYear(const int year) const;
    int getDaysInMonth(const int year, const int month) const;
    int daysInYear(const int year) const;
    void setSystemDate();

    void dayOfMonth(int* dayOfYear, int* year, int* month);
    void setFormat1(const char* dateName);
    void setFormat2(const char* dateName);
    void setFormat3(const char* dateName);
    void setDate(const int day, const int month, const int year);
    int stringToNumber(const int start, const int end, const char* name);

private:
    int year_;
    int month_;
    int day_;
};

#endif /// __DATE_HPP__


