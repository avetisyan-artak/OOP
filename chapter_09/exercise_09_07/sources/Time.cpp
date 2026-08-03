#include "headers/Time.hpp"
#include <iostream>
#include <cassert>
#include <ctime>

Time::Time()
{
    const int timeSinceCreation = std::time(0);
    const int hour = (timeSinceCreation / 3600 + 4) % 24;
    const int minute = (timeSinceCreation / 60) % 60;
    const int second = (timeSinceCreation % 60);

    setHour(hour);
    setMinute(minute);
    setSecond(second);
}

Time::Time(const int hour, const int minute, const int second)
{
    setHour(hour);
    setMinute(minute);
    setSecond(second);
}

Time::Time(const Time& rhv)
{
    setHour(rhv.getHour());
    setMinute(rhv.getMinute());
    setSecond(rhv.getSecond());
}

void
Time::setHour(int hour)
{
    assert(hour >= 0 && hour < MAX_HOUR);
    hour_ = hour;
}

void
Time::setMinute(int minute)
{
    assert(minute >= 0 && minute < MAX_MINUTE);
    minute_ = minute;
}

void
Time::setSecond(int second)
{
    assert(second >= 0 && second < MAX_SECOND);
    second_ = second;
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
    if (MAX_SECOND == second_) {
        second_ = 0;
        ++minute_;
    }

    if (MAX_MINUTE == minute_) {
        minute_ = 0;
        ++hour_;
    }

    if (MAX_HOUR == hour_) {
        hour_ = 0;
    }
}

void
Time::displayMessage() const
{
    std::cout << hour_ << ":" << minute_ << ":" << second_ << ":" << std::endl;
}

