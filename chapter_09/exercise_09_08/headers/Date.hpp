#ifndef __DATE_HPP__
#define __DATE_HPP__

const int MAX_DAY = 31;
const int MAX_MONTH = 12;

class Date
{
public:
    Date();
    Date(const int month, const int day, const int year);
    Date(const Date& rhv);

    void setMonth(int month);
    void setDay(int day);
    void setYear(int year);

    int getMonth() const;
    int getDay() const;
    int getYear() const;

    void nextDay();

    void print() const;

private:
    int month_;
    int day_;
    int year_;
};

#endif /// __DATE_HPP__

