#ifndef __CIRCLE_HPP__
#define __CIRCLE_HPP__
#include "headers/TwoDimensionalShape.hpp"

class Circle: public TwoDimensionalShape
{
public:
    Circle(const double radius = 1.0);
    Circle(const Circle& rhv);
    virtual ~Circle() {}

    void setRadius(const double radius);
    double getRadius() const;

    virtual double getArea() const;
    virtual void print() const;

private:
    double radius_;
};

#endif /// __CIRCLE_HPP__

