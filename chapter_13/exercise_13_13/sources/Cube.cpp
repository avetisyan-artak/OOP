#include "headers/Cube.hpp"
#include <cassert>
#include <iostream>

Cube::Cube(const double side1)
    : side1_(side1)
{
}

Cube::Cube(const Cube& rhv)
    : side1_(rhv.side1_)
{
}

void
Cube::setSide(const double side1)
{
    assert(side1 > 0);
    side1_ = side1;
}

double
Cube::getSide() const
{
    return side1_;
}

double
Cube::getArea() const
{
    return COUNT_OF_SIDES * getSide() * getSide();
}

double
Cube::getVolume() const
{
    return getSide() * getSide() * getSide();
}

void
Cube::print() const
{
    std::cout << "Cube side - " << getSide() << std::endl
              << "Cube Area - " << getArea() << std::endl
              << "Cube Volume - " << getVolume() << std::endl;
}

