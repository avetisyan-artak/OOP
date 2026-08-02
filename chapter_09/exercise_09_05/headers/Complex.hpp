#ifndef __COMPLEX_HPP__
#define __COMPLEX_HPP__

class Complex
{
public:
    Complex();
    Complex(const double realPart, const double imaginaryPart);
    Complex(const Complex& rhv);

    void setRealPart(double realPart);
    void setImaginaryPart(double imaginaryPart);

    double getRealPart() const;
    double getImaginaryPart() const;

    Complex sumOfNumbers(const Complex& rhv);
    Complex subOfNumbers(const Complex& rhv);
    Complex multiplication(const Complex& rhv);

    void printResult() const;

private:
    double realPart_;
    double imaginaryPart_;
};

#endif /// __COMPLEX_HPP__

