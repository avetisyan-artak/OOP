#ifndef __RATIONAL_HPP__
#define __RATIONAL_HPP__

class Rational
{
public:
    Rational();
    Rational(const int numerator, const int denominator);
    Rational(const Rational& rhv);

    void setNumerator(int numerator);
    void setDenominator(int denominator);

    int getNumerator() const;
    int getDenominator() const;
    int gcd(const int numerator, const int denominator);

    Rational sumOfNumbers(const Rational& rhv);
    Rational subOfNumbers(const Rational& rhv);
    Rational multiplicationOfNumbers(const Rational& rhv);
    Rational dividingOfNumbers(const Rational& rhv);

    void printResult() const;
    void printFloatingPoint() const;

private:
    int numerator_;
    int denominator_;
};

#endif /// __RATIONAL_HPP__

