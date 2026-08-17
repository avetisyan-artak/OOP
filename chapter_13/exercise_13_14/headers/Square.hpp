#ifndef __SQUARE_HPP__
#define __SQUARE_HPP__
#include "TwoDimensionalShape.hpp"

class Square: public TwoDimensionalShape
{
public:
    Square(const double side1 = 1.0, const char symbol = '*');
    virtual ~Square() {}

    void setSymbol(const char symbol);
    char getSymbol() const;

    void setSide(const double side1);
    double getSide() const;

    virtual void print() const;
    virtual void draw() const;
    virtual double getArea() const;

private:
    double side1_;
    char symbol_;
};

#endif /// __SQUARE_HPP__

