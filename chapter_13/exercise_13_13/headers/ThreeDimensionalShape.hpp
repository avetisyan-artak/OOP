#ifndef __TREE_DIMENSIONAL_SHAPE_HPP__
#define __TREE_DIMENSIONAL_SHAPE_HPP__
#include "headers/Shape.hpp"

class ThreeDimensionalShape: public Shape
{
public:
    ThreeDimensionalShape() {}
    virtual ~ThreeDimensionalShape() {}

    virtual double getArea()   const = 0;
    virtual double getVolume() const = 0;
    virtual void print()       const = 0;

};

#endif /// __TREE_DIMENSIONAL_SHAPE_HPP__

