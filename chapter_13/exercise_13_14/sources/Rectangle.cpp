#include "headers/Rectangle.hpp"
#include <cassert>
#include <iostream>

Rectangle::Rectangle(const double width, const double length, const char symbol)
    : width_(width)
    , length_(length)
    , symbol_(symbol)
{
}

void
Rectangle::setWidth(const double width)
{
    assert(width > 0);
    width_ = width;
}

double
Rectangle::getWidth() const
{
    return width_;
}

double
Rectangle::getLength() const
{
    return length_;
}

void
Rectangle::setLength(const double length)
{
    assert(length > 0);
    length_ = length;
}

void
Rectangle::setSymbol(const char symbol)
{
      assert(std::isprint(symbol));
      symbol_ = symbol;
}

char
Rectangle::getSymbol() const
{
    return symbol_;
}

double
Rectangle::getArea() const
{
    return getWidth() * getLength();
}

void
Rectangle::print() const
{
    std::cout << "Rectangle width = " << getWidth() << std::endl
              << "Rectangle length = " << getLength() << std::endl
              << "Rectangle Area = " << getArea() << std::endl;
}

void
Rectangle::draw() const
{
    const int width = static_cast<int>(getWidth());
    const int length = static_cast<int>(getLength());
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < length; ++j) {
            std::cout << ((0 == i || 0 == j || i == width - 1 || j == length - 1) ? getSymbol() : ' ');
        }
        std::cout << std::endl;
    }
}

