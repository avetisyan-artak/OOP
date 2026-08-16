#ifndef __TETRAHEDRON_HPP__
#define __TETRAHEDRON_HPP__
#include "headers/ThreeDimensionalShape.hpp"

class Tetrahedron: public ThreeDimensionalShape
{
public:
    Tetrahedron(const double sideLength = 1);
    Tetrahedron(const Tetrahedron& rhv);
    virtual ~Tetrahedron() {}

    void setSideLength(const double sideLength);
    double getSideLength() const;

    virtual double getArea() const;
    virtual double getVolume() const;
    virtual void print() const;

private:
    double sideLength_;
};

#endif /// __TETRAHEDRON_HPP__

