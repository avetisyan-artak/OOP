#ifndef __TRIANGLE_HPP
#define __TRIANGLE_HPP
#include "headers/TwoDimensionalShape.hpp"

class Triangle: public TwoDimensionalShape
{
public:
    Triangle(const double side1 = 1, const double side2 = 1, const double side3 = 1);
    Triangle(const Triangle& rhv);
    virtual ~Triangle();

    void setSide1(const double side1);
    void setSide2(const double side2);
    void setSide3(const double side3);

    double getSide1() const;
    double getSide2() const;
    double getSide3() const;

    virtual double getArea() const;
    virtual void print() const;

private:
    double side1_;
    double side2_;
    double side3_;
};

#endif /// __TRIANGLE_HPP

