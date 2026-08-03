#include "../headers/HugeInteger.hpp"
#include <iostream>
#include <cassert>
#include <cstring>
#include <cctype>

HugeInteger::HugeInteger()
{
    init();
}

HugeInteger::HugeInteger(const HugeInteger& rhv)
{
    for (int i = 0; i < SIZE; ++i) {
        digits_[i] = rhv.digits_[i];
    }
}

HugeInteger::HugeInteger(int number1)
{
    init();

    int index = SIZE - 1;

    while (number1 != 0 && index >= 0) {
        digits_[index] = number1 % BASE;
        number1 /= BASE;
        --index;
    }
}

HugeInteger::HugeInteger(const char* number1)
{
    setNumber(number1);
}

void
HugeInteger::init()
{
    for (int i = 0; i < SIZE; ++i) {
        digits_[i] = 0;
    }
}

bool
HugeInteger::isDigit(const char* number1) const
{
    for (int i = 0; number1[i] != '\0'; ++i) {
        if (!std::isdigit(number1[i])) {
            return false;
        }
    }

    return true;
}

bool
HugeInteger::isZero()
{
    for (int i = 0; i < SIZE; ++i) {
        if (digits_[i] != 0) {
            return false;
        }
    }

    return true;
}

void
HugeInteger::setNumber(int number1)
{
    init();

    int index = SIZE - 1;

    while (number1 != 0 && index >= 0) {
        digits_[index] = number1 % BASE;
        number1 /= BASE;
        --index;
    }
}

void
HugeInteger::setNumber(const char* number1)
{
    assert(isDigit(number1));
    assert(std::strlen(number1) < SIZE);

    init();

    int length = std::strlen(number1);
    int start = SIZE - length;

    for (int i = 0; i < length; ++i) {
        digits_[start + i] = number1[i] - '0';
    }
}

void
HugeInteger::output()
{
    bool zero = true;

    for (int i = 0; i < SIZE; ++i) {

        if (zero && digits_[i] == 0) {
            continue;
        }

        zero = false;
        std::cout << digits_[i];
    }

    if (zero) {
        std::cout << "0";
    }

    std::cout << std::endl;
}

HugeInteger
HugeInteger::add(const HugeInteger& rhv)
{
    HugeInteger result;

    int carry = 0;

    for (int i = SIZE - 1; i >= 0; --i) {

        int sum = digits_[i] + rhv.digits_[i] + carry;

        result.digits_[i] = sum % BASE;
        carry = sum / BASE;
    }

    return result;
}

HugeInteger
HugeInteger::substract(const HugeInteger& rhv)
{
    HugeInteger result;

    int borrow = 0;

    for (int i = SIZE - 1; i >= 0; --i) {

        int value = digits_[i] - rhv.digits_[i] - borrow;

        if (value < 0) {
            value += BASE;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result.digits_[i] = value;
    }

    return result;
}

HugeInteger
HugeInteger::multiply(const HugeInteger& rhv)
{
    HugeInteger result;

    for (int i = SIZE - 1; i >= 0; --i) {

        int carry = 0;

        for (int j = SIZE - 1; j >= 0; --j) {

            int pos = i + j - (SIZE - 1);

            if (pos < 0) {
                continue;
            }

            int product =
                digits_[i] * rhv.digits_[j]
                + result.digits_[pos]
                + carry;

            result.digits_[pos] = product % BASE;
            carry = product / BASE;
        }
    }

    return result;
}

bool
HugeInteger::isEqualTo(const HugeInteger& rhv) const
{
    for (int i = 0; i < SIZE; ++i) {

        if (digits_[i] != rhv.digits_[i]) {
            return false;
        }
    }

    return true;
}

bool
HugeInteger::isNotEqualTo(const HugeInteger& rhv) const
{
    return !isEqualTo(rhv);
}

bool
HugeInteger::isLessThan(const HugeInteger& rhv) const
{
    for (int i = 0; i < SIZE; ++i) {

        if (digits_[i] < rhv.digits_[i]) {
            return true;
        }

        if (digits_[i] > rhv.digits_[i]) {
            return false;
        }
    }

    return false;
}

bool
HugeInteger::isGreaterThan(const HugeInteger& rhv) const
{
    return rhv.isLessThan(*this);
}

bool
HugeInteger::isGreaterThanOrEqualTo(const HugeInteger& rhv) const
{
    return !isLessThan(rhv);
}

bool
HugeInteger::isLessThanOrEqualTo(const HugeInteger& rhv) const
{
    return !isGreaterThan(rhv);
}

