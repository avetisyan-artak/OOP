#include "../headers/Time.hpp"
#include <iostream>
#include <ctime>


Time::Time()
{
    const int timeSinceCreation = std::time(0);

    const int hour = (timeSinceCreation / SECONDS_IN_HOUR + TIMEZONE_OFFSET) % HOURS_IN_DAY;
    const int minute = (timeSinceCreation / SECONDS_IN_MINUTE) % MINUTES_IN_HOUR;
    const int second = timeSinceCreation % SECONDS_IN_MINUTE;

    setHour(hour);
    setMinute(minute);
    setSecond(second);
}


Time::Time(Time& rhv)
{
    setHour(rhv.getHour());
    setMinute(rhv.getMinute());
    setSecond(rhv.getSecond());
}


Time::Time(const int hour, const int minute, const int second)
{
    setHour(hour);
    setMinute(minute);
    setSecond(second);
}


bool
Time::setHour(const int hour)
{
    if (hour >= 0 && hour < MAX_HOURS) {
        hour_ = hour;
        return true;
    }

    return false;
}


bool
Time::setMinute(const int minute)
{
    if (minute >= 0 && minute < MAX_MINUTES) {
        minute_ = minute;
        return true;
    }

    return false;
}


bool
Time::setSecond(const int second)
{
    if (second >= 0 && second < MAX_SECONDS) {
        second_ = second;
        return true;
    }

    return false;
}


int
Time::getHour() const
{
    return hour_;
}


int
Time::getMinute() const
{
    return minute_;
}


int
Time::getSecond() const
{
    return second_;
}


void
Time::tick()
{
    ++second_;

    if (second_ >= MAX_SECONDS) {
        second_ = 0;
        ++minute_;
    }

    if (minute_ >= MAX_MINUTES) {
        minute_ = 0;
        ++hour_;
    }

    if (hour_ >= HOURS_IN_DAY) {
        hour_ = 0;
    }
}


void
Time::displayTime() const
{
    std::cout << (hour_ < 10 ? "0" : "")
              << hour_ << ":"
              << (minute_ < 10 ? "0" : "")
              << minute_ << ":"
              << (second_ < 10 ? "0" : "")
              << second_
              << std::endl;
}

