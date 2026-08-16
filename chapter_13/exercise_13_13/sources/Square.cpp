#include "headers/Square.hpp"
#include <cassert>
#include <iostream>

Square::Square(const double side1)
    : side1_(side1)
{
}

Square::Square(const Square& rhv)
    : side1_(rhv.side1_)
{
}

void
Square::setSide(const double side1)
{
    assert(side1 > 0);
    side1_ = side1;
}

double
Square::getSide() const
{
    return side1_;
}

double
Square::getArea() const
{
    return getSide() * getSide();
}

void
Square::print() const
{
    std::cout << "Square radius = " << getSide() << std::endl
              << "Square Area = " << getArea() << std::endl;
}

