#include "headers/Sphere.hpp"
#include <cassert>
#include <cmath>
#include <iostream>

Sphere::Sphere(const double radius)
    : radius_(radius)
{
}

Sphere::Sphere(const Sphere& rhv)
    : radius_(rhv.radius_)
{
}

void
Sphere::setRadius(const double radius)
{
    assert(radius > 0);
    radius_ = radius;
}

double
Sphere::getRadius() const
{
    return radius_;
}

double
Sphere::getVolume() const
{
    return (4.0 / 3.0) * M_PI * radius_ * radius_ * radius_;
}

double
Sphere::getArea() const
{
    return 4 * M_PI * getRadius() * getRadius();
}

void
Sphere::print() const
{
    std::cout << "Sphere radius = " << getRadius() << std::endl
              << "Sphere Area = " << getArea() << std::endl
              << "Sphere Volume = " << getVolume() << std::endl;
}

