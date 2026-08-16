#include "headers/Circle.hpp"
#include <cassert>
#include <cmath>
#include <iostream>

Circle::Circle(const double radius)
    : radius_(radius)
{
}

Circle::Circle(const Circle& rhv)
    : radius_(rhv.radius_)
{
}

void
Circle::setRadius(const double radius)
{
    assert(radius > 0);
    radius_ = radius;
}

double
Circle::getRadius() const
{
    return radius_;
}

double
Circle::getArea() const
{
    return M_PI * getRadius() * getRadius();
}

void
Circle::print() const
{
    std::cout << "Circle radius = " << getRadius() << std::endl
              << "Circle Area = " << getArea() << std::endl;
}

