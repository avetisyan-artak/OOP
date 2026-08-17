#include "headers/Square.hpp"
#include <iostream>
#include <cassert>

Square::Square(const double side1, const char symbol)
    : side1_(side1)
    , symbol_(symbol)
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

void
Square::setSymbol(const char symbol)
{
    symbol_ = symbol;
}

char
Square::getSymbol() const
{
    return symbol_;
}

double
Square::getArea() const
{
    return side1_ * side1_;
}

void
Square::print() const
{
    std::cout << "Square side is " << side1_
              << "Square area is " << getArea()
              << std::endl;
}

void
Square::draw() const
{
    const int size = getSide() - 1;
    const char character = getSymbol();

    for (int i = 0; i < getSide(); ++i) {
        for (int j = 0; j < getSide(); ++j) {
            std::cout << ((0 == i || 0 == j || size == i || size == j) ? character : ' ');
        }
        std::cout << std::endl;
    }
}

