#include "headers/Rectangle.hpp"
#include <iostream>
#include <cassert>

Rectangle::Rectangle()
{
    setLength(1.0);
    setWidth(1.0);
}

Rectangle::Rectangle(const double length, const double width)
{
    setLength(length);
    setWidth(width);
}

Rectangle::Rectangle(const Rectangle& rhv)
{
    setLength(rhv.getLength());
    setWidth(rhv.getWidth());
}

bool
Rectangle::setLength(double length)
{
    if (length > 0.0 && length < 20.0) {
        length_ = length;
        return true;
    }

    return false;
}

bool
Rectangle::setWidth(double width)
{
    if (width > 0.0 && width < 20.0) {
        width_ = width;
        return true;
    }

    return false;
}

double
Rectangle::getLength() const
{
    return length_;
}

double
Rectangle::getWidth() const
{
    return width_;
}

double
Rectangle::getPerimeter() const
{
    return (2 * length_ + 2 * width_);
}

double
Rectangle::getArea() const
{
    return (length_ * width_);
}

void
Rectangle::printResult() const
{
    std::cout << "Perimeter is " << getPerimeter()
              << "Area is " << getArea();
}

