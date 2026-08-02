#include "headers/Complex.hpp"
#include <iostream>

Complex::Complex()
    : realPart_(0.0), imaginaryPart_(0.0)
{}

Complex::Complex(const double realPart, const double imaginaryPart)
{
    setRealPart(realPart);
    setImaginaryPart(imaginaryPart);
}

Complex::Complex(const Complex& rhv)
{
    setRealPart(rhv.getRealPart());
    setImaginaryPart(rhv.getImaginaryPart());
}

void
Complex::setRealPart(double realPart)
{
    realPart_ = realPart;
}

void
Complex::setImaginaryPart(double imaginaryPart)
{
    imaginaryPart_ = imaginaryPart;
}

double
Complex::getRealPart() const
{
    return realPart_;
}

double
Complex::getImaginaryPart() const
{
    return imaginaryPart_;
}

Complex
Complex::sumOfNumbers(const Complex& rhv)
{
    return Complex(realPart_ + rhv.getRealPart(), imaginaryPart_ + rhv.getImaginaryPart());
}

Complex
Complex::subOfNumbers(const Complex& rhv)
{
    return Complex(realPart_ - rhv.getRealPart(), imaginaryPart_ - rhv.getImaginaryPart());
}

Complex
Complex::multiplication(const Complex& rhv)
{
    const double real = realPart_ * rhv.realPart_ - imaginaryPart_ * rhv.imaginaryPart_;
    const double image = realPart_ * rhv.imaginaryPart_ + imaginaryPart_ * rhv.realPart_;
    return Complex(real, image);
}

void
Complex::printResult() const
{
    std::cout << realPart_ << " + " << imaginaryPart_ << "i" << std::endl;
}

