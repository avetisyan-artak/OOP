#include "headers/DateAndTime.hpp"

const int months[MONTH_COUNT] = {31, 28, 31, 30, 31, 30,
                                 31, 31, 30, 31, 30, 31};

DateAndTime::DateAndTime()
{
    setYear(2000);
    setMonth(1);
    setDay(1);

    setHours(0);
    setMinutes(0);
    setSeconds(0);
}

DateAndTime::DateAndTime(const int year, const int month, const int day,
                         const int hour, const int minute, const int second)
{
    assert(day <= getDaysInMonth(year, month));

    setYear(year);
    setMonth(month);
    setDay(day);

    setHours(hour);
    setMinutes(minute);
    setSeconds(second);
}

void
DateAndTime::setHours(const int hour)
{
    assert(hour >= 0 && hour < MAX_HOUR);
    hour_ = hour;
}

int
DateAndTime::getHours() const
{
    return hour_;
}

void
DateAndTime::setMinutes(const int minute)
{
    assert(minute >= 0 && minute < MAX_MINUTES);
    minute_ = minute;
}

int
DateAndTime::getMinutes() const
{
    return minute_;
}

void
DateAndTime::setSeconds(const int second)
{
    assert(second >= 0 && second < MAX_SECONDS);
    second_ = second;
}

int
DateAndTime::getSeconds() const
{
    return second_;
}

void
DateAndTime::setYear(const int year)
{
    assert(year >= MIN_YEAR && year <= MAX_YEAR);
    year_ = year;
}

int
DateAndTime::getYear() const
{
    return year_;
}

void
DateAndTime::setMonth(const int month)
{
    assert(month > 0 && month <= MONTH_COUNT);
    month_ = month;
}

int
DateAndTime::getMonth() const
{
    return month_;
}

void
DateAndTime::setDay(const int day)
{
    assert(day > 0 && day <= MAX_DAY);
    day_ = day;
}

int
DateAndTime::getDay() const
{
    return day_;
}

bool
DateAndTime::isLeapYear(const int year) const
{
    return (0 == year % 400) ||
           (0 == year % 4 && year % 100 != 0);
}

int
DateAndTime::getDaysInMonth(const int year, const int month) const
{
    assert(month > 0 && month <= MONTH_COUNT);
    assert(year >= MIN_YEAR && year <= MAX_YEAR);

    if (2 == month && isLeapYear(year)) {
        return 29;
    }

    return months[month - 1];
}

bool
DateAndTime::isNextDay()
{
    ++second_;

    if (second_ >= MAX_SECONDS) {
        setSeconds(0);
        ++minute_;
    }

    if (minute_ >= MAX_MINUTES) {
        setMinutes(0);
        ++hour_;
    }

    if (hour_ >= MAX_HOUR) {
        setHours(0);
        return true;
    }

    return false;
}

void
DateAndTime::nextDay()
{
    ++day_;

    if (day_ > getDaysInMonth(year_, month_)) {
        day_ = 1;
        ++month_;
    }

    if (month_ > MONTH_COUNT) {
        month_ = 1;
        ++year_;
    }
}

void
DateAndTime::tick()
{
    if (isNextDay()) {
        nextDay();
    }
}

void
DateAndTime::printUniversal() const
{
    const char previous = std::cout.fill('0');

    std::cout << std::setw(SPACE_SIZE) << hour_ << ":"
              << std::setw(SPACE_SIZE) << minute_ << ":"
              << std::setw(SPACE_SIZE) << second_;

    std::cout << std::setfill(previous);
}

void
DateAndTime::printStandard() const
{
    const int hour = getHours();
    const char previous = std::cout.fill('0');

    std::cout << ((0 == hour || HALF_DAY == hour)
                  ? HALF_DAY
                  : hour % HALF_DAY)
              << ":"
              << std::setw(SPACE_SIZE) << getMinutes()
              << ":"
              << std::setw(SPACE_SIZE) << getSeconds()
              << (hour < HALF_DAY ? " AM" : " PM");

    std::cout << std::setfill(previous);
}

void
DateAndTime::printDate() const
{
    std::cout << getDay() << "/"
              << getMonth() << "/"
              << getYear()
              << std::endl;
}

void
DateAndTime::printDateAndTime() const
{
    printUniversal();
    printDate();
}

