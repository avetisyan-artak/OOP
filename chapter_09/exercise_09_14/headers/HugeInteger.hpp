#ifndef __HUGE_INTEGER_HPP__
#define __HUGE_INTEGER_HPP__

const int SIZE = 40;
const int BASE = 10;

class HugeInteger
{
public:
    HugeInteger();
    HugeInteger(const HugeInteger& rhv);
    HugeInteger(int number1);
    HugeInteger(const char* number1);

    void init();
    void setNumber(int number1);
    void setNumber(const char* number1);
    void output();

    HugeInteger add(const HugeInteger& rhv);
    HugeInteger substract(const HugeInteger& rhv);
    HugeInteger multiply(const HugeInteger& rhv);

    bool isEqualTo(const HugeInteger& rhv) const;
    bool isDigit(const char* number1) const;
    bool isZero();
    bool isNotEqualTo(const HugeInteger& rhv) const;
    bool isGreaterThan(const HugeInteger& rhv) const;
    bool isLessThan(const HugeInteger& rhv) const;
    bool isGreaterThanOrEqualTo(const HugeInteger& rhv) const;
    bool isLessThanOrEqualTo(const HugeInteger& rhv) const;

private:
    int digits_[SIZE];
};

#endif /// __HUGE_INTEGER_HPP__

