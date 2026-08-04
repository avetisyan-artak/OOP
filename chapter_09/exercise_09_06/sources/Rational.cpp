#include "headers/Rational.hpp"
#include <iostream>
#include <cassert>

Rational::Rational()
    : numerator_(0), denominator_(1)
{}

Rational::Rational(const int numerator, const int denominator)
{
    assert(denominator != 0);
    const int divisor = (0 == numerator ? 1 : gcd(numerator, denominator) * ((numerator < 0 && denominator > 0) ? -1 : 1));
    setNumerator(numerator / divisor);
    setDenominator(denominator / divisor);
}

Rational::Rational(const Rational& rhv)
{
    setNumerator(rhv.getNumerator());
    setDenominator(rhv.getDenominator());
}

void
Rational::setNumerator(int numerator)
{
    numerator_ = numerator;
}

void
Rational::setDenominator(int denominator)
{
    assert(denominator != 0);
    denominator_ = denominator;
}

int
Rational::getNumerator() const
{
    return numerator_;
}

int
Rational::getDenominator() const
{
    return denominator_;
}

Rational
Rational::sumOfNumbers(const Rational& rhv)
{
    const int numerator1 = getNumerator() * rhv.getDenominator() + getDenominator() * rhv.getNumerator();
    const int denominator1 = getDenominator() * rhv.getDenominator();
    return Rational(numerator1, denominator1);
}

Rational
Rational::subOfNumbers(const Rational& rhv)
{
    const int numerator1 = getNumerator() * rhv.getDenominator() - getDenominator() * rhv.getNumerator();
    const int denominator1 = getDenominator() * rhv.getDenominator();
    return Rational(numerator1, denominator1);
}

Rational
Rational::multiplicationOfNumbers(const Rational& rhv)
{
    const int numerator1 = getNumerator() * rhv.getNumerator();
    const int denominator1 = getDenominator() * rhv.getDenominator();
    return Rational(numerator1, denominator1);
}

Rational
Rational::dividingOfNumbers(const Rational& rhv)
{
    assert(rhv.numerator_ != 0);
    const int numerator1 = getNumerator() * rhv.getDenominator();
    const int denominator1 = getDenominator() * rhv.getNumerator();
    return Rational(numerator1, denominator1);
}

int
Rational::gcd(const int numerator, const int denominator)
{
    int a = numerator;
    int b = denominator;
    while(b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

void
Rational::printResult() const
{
    std::cout << getNumerator() << "/" << getDenominator() << std::endl;
}

void
Rational::printFloatingPoint() const
{
    std::cout << static_cast<double>(getNumerator() / getDenominator()) << std::endl;
}
