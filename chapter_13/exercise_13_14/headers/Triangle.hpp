#ifndef __TRIANGLE_HPP__
#define __TRIANGLE_HPP__
#include "TwoDimensionalShape.hpp"

class Triangle: public TwoDimensionalShape
{
public:
    Triangle(const double side1 = 1.0, const double side2 = 1.0, const double side3 = 1.0, const char symbol = '*');
    virtual ~Triangle() {}

    void setSide1(const double side1);
    double getSide1() const;

    void setSide2(const double side2);
    double getSide2() const;

    void setSide3(const double side3);
    double getSide3() const;

    void setSymbol(const char symbol);
    char getSymbol() const;

    virtual void print() const;
    virtual void draw() const;
    virtual double getArea() const;

private:
    double side1_;
    double side2_;
    double side3_;
    char symbol_;
};

#endif /// __TRIANGLE_HPP__









