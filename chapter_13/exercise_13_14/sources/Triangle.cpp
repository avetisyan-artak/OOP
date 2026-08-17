#include "headers/Triangle.hpp"
#include <cassert>
#include <iostream>
#include <cmath>

Triangle::Triangle(const double side1, const double side2, const double side3, const char symbol)
    : side1_(side1)
    , side2_(side2)
    , side3_(side3)
    , symbol_(symbol)
{
}

void
Triangle::setSide1(const double side1)
{
    assert(side1 > 0);
    side1_ = side1;
}

void
Triangle::setSide2(const double side2)
{
    assert(side2 > 0);
    side2_ = side2;
}

void
Triangle::setSide3(const double side3)
{
    assert(side3 > 0);
    side3_ = side3;
}

double
Triangle::getSide1() const
{
    return side1_;
}

double
Triangle::getSide2() const
{
    return side2_;
}

double
Triangle::getSide3() const
{
    return side3_;
}

void
Triangle::setSymbol(const char symbol)
{
    assert(std::isprint(symbol));
    symbol_ = symbol;
}

char
Triangle::getSymbol() const
{
    return symbol_;
}

double
Triangle::getArea() const
{
    double p = (getSide1() + getSide2() + getSide3()) / 2.0;
    return std::sqrt(p * (p - getSide1()) * (p - getSide2()) * (p - getSide3()));
}

void
Triangle::print() const
{
    std::cout << "Triangle first side = " << getSide1() << std::endl
              << "Triangle second side = " << getSide2() << std::endl
              << "Triangle third side = " << getSide3() << std::endl
              << "Triangle Area = " << getArea() << std::endl;
}

void
Triangle::draw() const
{
    const int base = static_cast<int>(getSide1());
    const int height = static_cast<int>(getSide2());
    for (int i = 0; i < base; ++i) {
        for (int j = 0; j < height; ++j) {
            std::cout << ((0 == j || base - 1 == i || i == j) ? getSymbol() : ' ');
        }
        std::cout << std::endl;
    }
}

