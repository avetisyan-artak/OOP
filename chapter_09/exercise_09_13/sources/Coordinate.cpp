#include "headers/Coordinate.hpp"
#include <iostream>

Coordinate::Coordinate(const double x, const double y)
    : x_(x)
    , y_(y)
{
}

Coordinate::Coordinate(const Coordinate& rhv)
    : x_(rhv.x_)
    , y_(rhv.y_)
{
}

void
Coordinate::setX(const double x)
{
    x_ = x;
}

void
Coordinate::setY(const double y)
{
    y_ = y;
}

double
Coordinate::getX() const
{
    return x_;
}

double
Coordinate::getY() const
{
    return y_;
}

void
Coordinate::print() const
{
    std::cout << "(" << x_ << ", " << y_ << ")";
}

