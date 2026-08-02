#ifndef __EXERCISE_09_04_HPP__
#define __EXERCISE_09_04_HPP__

class Time
{
public:
    Time();
    Time(const int hour, const int minute, const int second);
    Time(const Time& rhv);

    void setHour(int hour);
    void setMinute(int minute);
    void setSecond(int second);

    int getHour() const;
    int getMinute() const;
    int getSecond() const;

    void displayMessage() const;

private:
    int hour_;
    int minute_;
    int second_;
};

#endif /// __EXERCISE_09_04_HPP__

