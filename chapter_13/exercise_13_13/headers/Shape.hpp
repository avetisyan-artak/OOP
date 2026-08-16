#ifndef __SHAPE_HPP__
#define __SHAPE_HPP__

class Shape
{
public:
    Shape() {};
    virtual ~Shape() {}

    virtual double getArea() const = 0;
    virtual void print()     const = 0;
};

#endif /// __SHAPE_HPP__

