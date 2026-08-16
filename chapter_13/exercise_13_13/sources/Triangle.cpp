#include "headers/Triangle.hpp"
#include <cassert>
#include <cmath>
#include <iostream>

Triangle::Triangle(const double side1, const double side2, const double side3)
    : side1_(side1)
    , side2_(side2)
    , side3_(side3)
{
}

Triangle::Triangle(const Triangle& rhv)
    : side1_(rhv.side1_)
    , side2_(rhv.side2_)
    , side3_(rhv.side3_)
{
}

Triangle::~Triangle()
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
              << "Triangle third side = " << getSide3() << std::endl;
}

