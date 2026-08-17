#ifndef __RECTANGLE_HPP__
#define __RECTANGLE_HPP__
#include "TwoDimensionalShape.hpp"

class Rectangle: public TwoDimensionalShape
{
public:
    Rectangle(const double width = 1.0, const double length = 1.0, const char symbol = '*');
    virtual ~Rectangle() {}

    void setSymbol(const char symbol);
    char getSymbol() const;

    void setLength(const double length);
    double getLength() const;

    void setWidth(const double width);
    double getWidth() const;

    virtual void print() const;
    virtual void draw() const;
    virtual double getArea() const;

private:
    double width_;
    double length_;
    char symbol_;
};

#endif /// __RECTANGLE_HPP__

