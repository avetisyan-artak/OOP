#ifndef __CUBE_HPP__
#define __CUBE_HPP__
#include "headers/ThreeDimensionalShape.hpp"

const int COUNT_OF_SIDES = 6;

class Cube: public ThreeDimensionalShape
{
public:
    Cube(const double radius = 1.0);
    Cube(const Cube& rhv);
    virtual ~Cube() {}

    void setSide(const double side1);
    double getSide() const;

    virtual double getArea() const;
    virtual double getVolume() const;
    virtual void print() const;

private:
    double side1_;
};

#endif /// __CUBE_HPP__

