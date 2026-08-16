#ifndef __SQUARE_HPP__
#define __SQUARE_HPP__
#include "headers/TwoDimensionalShape.hpp"

class Square: public TwoDimensionalShape
{
public:
    Square(const double side1 = 0.0);
    Square(const Square& rhv);
    virtual ~Square() {}

    void setSide(const double side1);
    double getSide() const;

    virtual double getArea() const;
    virtual void print() const;

private:
    double side1_;
};

#endif /// __SQUARE_HPP__

