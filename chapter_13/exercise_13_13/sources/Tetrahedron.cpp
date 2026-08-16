#include "headers/Tetrahedron.hpp"
#include <cassert>
#include <cmath>
#include <iostream>

Tetrahedron::Tetrahedron(const double sideLength)
    : sideLength_(sideLength)
{
}

Tetrahedron::Tetrahedron(const Tetrahedron& rhv)
    : sideLength_(rhv.sideLength_)
{
}

void
Tetrahedron::setSideLength(const double sideLength)
{
    assert(sideLength > 0);
    sideLength_ = sideLength;
}

double
Tetrahedron::getSideLength() const
{
    return sideLength_;
}

double
Tetrahedron::getArea() const
{
    return (std::sqrt(3) * getSideLength() * getSideLength());
}

double
Tetrahedron::getVolume() const
{
    return (std::pow(getSideLength(), 3) / (6 * std::sqrt(2.0)));
}

void
Tetrahedron::print() const
{
    std::cout << "Tetrahedron edge = " << getSideLength() << std::endl
              << "Tetrahedron Area = " << getArea() << std::endl
              << "Tetrahedron Volume = " << getVolume() << std::endl;
}

