#ifndef __TIME_HPP__
#define __TIME_HPP__

const int MAX_HOURS = 24;
const int MAX_MINUTES = 60;
const int MAX_SECONDS = 60;
const int SECONDS_IN_HOUR = 3600;
const int SECONDS_IN_MINUTE = 60;
const int MINUTES_IN_HOUR = 60;
const int HOURS_IN_DAY = 24;
const int TIMEZONE_OFFSET = 4;

class Time
{
public:
    Time();
    Time(const int hour, const int minute, const int second);
    Time(Time& rhv);

    bool setHour(const int hour);
    bool setMinute(const int minute);
    bool setSecond(const int second);

    int getHour() const;
    int getMinute() const;
    int getSecond() const;

    void tick();
    void displayTime() const;

private:
    int hour_;
    int minute_;
    int second_;
};

#endif /// __TIME_HPP__

