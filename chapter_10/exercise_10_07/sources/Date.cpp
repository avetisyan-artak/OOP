#include "../headers/Date.hpp"

#include <iostream>
#include <cassert>
#include <ctime>
#include <cstring>

const int months[MONTH_COUNT] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
static const char* monthNames[MONTH_COUNT] = {"January", "February", "March","April",
                                            "May", "June", "July", "August",
                                            "September","October", "November", "December"};

Date::Date()
{
    setSystemDate();
}

Date::Date(const char* dateName)
{
    switch (getFormat(dateName)) {
    case FORMAT_1: setFormat1(dateName);  break;
    case FORMAT_2: setFormat2(dateName);  break;
    case FORMAT_3: setFormat3(dateName);  break;
    default:       assert(0);
    }
}

Format
Date::getFormat(const char* dateName)
{
    if (isRightFormat3(dateName)) {
        return FORMAT_3;
    }
    if (isRightFormat2(dateName)) {
        return FORMAT_2;
    }
    if (isRightFormat1(dateName)) {
        return FORMAT_1;
    }
    return ERROR;
}

Date::Date(const int year, const int month, const int day)
{
    assert(day <= getDaysInMonth(year, month));
    setYear(year);
    setMonth(month);
    setDay(day);
}

Date::Date(const std::string& monthName, const int day, const int year)
{
    assert(year >= MIN_YEAR && year <= MAX_YEAR);
    assert(day > 0 && day <= MAX_DAY);

    bool found = false;
    for (int i = 0; i < MONTH_COUNT; ++i) {
        if (monthNames[i] == monthName) {
            setMonth(i + 1);
            found = true;
            break;
        }
    }
    assert(found);
    setYear(year);
    setDay(day);
}

Date::Date(const int days, const int year)
{
    assert(days > 0 && days <= daysInYear(year));
    assert(year >= MIN_YEAR && year <= MAX_YEAR);

    setYear(year);

    int month = 1;
    int day = days;

    while (day > getDaysInMonth(year, month)) {
        day -= getDaysInMonth(year, month);
        ++month;
    }

    setMonth(month);
    setDay(day);
}

Date::Date(const Date& rhv)
{
    setDate(rhv.getMonth(), rhv.getDay(), rhv.getYear());
}

void
Date::setDate(const int month, const int day, const int year)
{
    setMonth(month);
    setYear(year);
    setDay(day);
}

void
Date::setMonth(const int month)
{
    assert(month >= MIN_MONTH && month <= MAX_MONTH);
    month_ = month;
}

void
Date::setDay(const int day)
{
    assert(day >= MIN_DAY && day <= getDaysInMonth(year_, month_));
    day_ = day;
}

void
Date::setYear(const int year)
{
    assert(year >= MIN_YEAR);
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
Date::setSystemDate()
{
    const time_t time1 = std::time(0);
    int days = time1 / 86400;

    int year = 1970;
    while (days >= daysInYear(year)) {
        days -= daysInYear(year);
        ++year;
    }
    setYear(year);

    int month = 1;
    while (days >= getDaysInMonth(year, month)) {
        days -= getDaysInMonth(year, month);
        ++month;
    }
    setMonth(month);

    const int day = static_cast<int>(days) + 1;
    setDay(day);
}

void
Date::nextDay()
{
    ++day_;
    if (day_ > getDaysInMonth(year_, month_)) {
        day_ = MIN_DAY;
        ++month_;
        if (month_ > MAX_MONTH) {
            month_ = MIN_MONTH;
            ++year_;
        }
    }
}

bool
Date::isLeapYear(const int year) const
{
    return (0 == year % LEAP_YEAR_DIV_BY_4 && 0 != year % LEAP_YEAR_DIV_BY_100) || (0 == year % LEAP_YEAR_DIV_BY_400);
}

bool
Date::isRightFormat1(const char* dateName)
{
    return (isDigit(0, 2, dateName) && '/' == dateName[2] &&
            isDigit(3, 5, dateName) && '/' == dateName[5] &&
            isDigit(6, 10, dateName));
}

bool
Date::isRightFormat2(const char* dateName)
{
    return (isDigit(0, 3, dateName) && ' ' == dateName[3] &&
            isDigit(4, 7, dateName));
}

bool
Date::isRightFormat3(const char* dateName)
{
    char monthStr[SIZE];
    extractLetters(dateName, monthStr);
    const int lengthString = std::strlen(dateName);

    return (isDigit(lengthString - 4, lengthString - 1, dateName) &&
            dateName[lengthString - 5] == ' ' &&
            dateName[lengthString - 6] == ',' &&
            isDigit(lengthString - 8, lengthString - 6, dateName) &&
            dateName[lengthString - 9] == ' ' &&
            getMonthInNumber(monthStr) != -1);
}

bool
Date::isDigit(const int start, const int end, const char* name)
{
    assert(start >= 0 && start < end);

    for (int i = start; i < end; ++i) {
        if (!std::isdigit(name[i])) {
            return false;
        }
    }

    return true;
}

int
Date::stringToNumber(const int start, const int end, const char* temp)
{
    int number = 0;

    for (int i = start; i < end; ++i) {
        number = number * 10 + (temp[i] - '0');
    }

    return number;
}

void
Date::setFormat1(const char* dateName)
{
    const int month = stringToNumber(0, 2, dateName);
    const int day = stringToNumber(3, 5, dateName);
    const int year = stringToNumber(6, 10, dateName);

    setDate(month, day, year);
}

void
Date::setFormat2(const char* dateName)
{
    int dayOfYears = stringToNumber(0, 3, dateName);
    int year = stringToNumber(4, 8, dateName);
    int month = 0;

    dayOfMonth(&dayOfYears, &year, &month);

    setDate(month, dayOfYears, year);
}

void
Date::setFormat3(const char* dateName)
{
    const int lengthString = std::strlen(dateName);
    const int year = stringToNumber(lengthString - 4, lengthString, dateName);
    const int day = stringToNumber(lengthString - 8, lengthString - 6, dateName);

    char monthStr[SIZE];
    extractLetters(dateName, monthStr);

    const int month = getMonthInNumber(monthStr);

    setDate(month, day, year);
}

void
Date::extractLetters(const char* dateName, char* month)
{
    int j = 0;

    for (int i = 0; dateName[i] != ' '; ++i) {
        if ((dateName[i] >= 'A' && dateName[i] <= 'Z') ||
            (dateName[i] >= 'a' && dateName[i] <= 'z')) {
            month[j++] = dateName[i];
        }
    }

    month[j] = '\0';
}

int
Date::getDayOfYear() const
{
    int day = getDay();
    const int month = getMonth();

    for (int i = 1; i < month; ++i) {
        day += getDaysInMonth(getYear(), i);
    }

    return day;
}

int
Date::getMonthInNumber(const char* monthName)
{
    for (int i = 0; i < MONTH_COUNT; ++i) {
        if (0 == std::strcmp(monthNames[i], monthName)) {
            return i + 1;
        }
    }

    return -1;
}

int
Date::daysInYear(const int year) const
{
    return isLeapYear(year) ? 366 : 365;
}

int
Date::getDaysInMonth(int year, int month) const
{
    assert(month > 0 && month <= MONTH_COUNT);
    assert(year >= MIN_YEAR && year <= MAX_YEAR);

    if (2 == month && isLeapYear(year)) {
        return 29;
    }

    return months[month - 1];
}

void
Date::dayOfMonth(int* dayOfYear, int* year, int* month)
{
    int day = *dayOfYear;
    int month1 = 1;

    while (day > getDaysInMonth(*year, month1)) {
        day -= getDaysInMonth(*year, month1);
        ++month1;
    }

    *dayOfYear = day;
    *month = month1;
}

bool
Date::isRightFormat(const char* dateName)
{
    return isRightFormat1(dateName) ||
           isRightFormat2(dateName) ||
           isRightFormat3(dateName);
}

void
Date::printNumeric() const
{
    std::cout << getDay() << '/' << getMonth() << '/' << getYear() << std::endl;
}

void
Date::printTextual() const
{
    std::cout << getDayOfYear() << " " << getYear() << std::endl;
}

void
Date::printLong() const
{
    std::cout << monthNames[getMonth() - 1] << " " << getDay() << ", "
              << getYear() << std::endl;
}

