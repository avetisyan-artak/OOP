#ifndef __RECTANGLE_HPP__
#define __RECTANGLE_HPP__
#include "headers/Coordinate.hpp"

const int COUNT_OF_TOP = 4;
const double EPSILON = 1e-9;
const double POWER = 2;
const int SIZE_CORD = 25;

class Rectangle
{
public:
    Rectangle(const Coordinate& A, const Coordinate& B, const Coordinate& C, const Coordinate& D, const char fill = ' ', const char perimeter = '*');
    Rectangle(const Rectangle& rhv);

    Coordinate getPointA() const;
    Coordinate getPointB() const;
    Coordinate getPointC() const;
    Coordinate getPointD() const;

    char getFillCharacter() const;
    char getPerimeterCharacter() const;

    void setFillCharacter(char fill);
    void setPerimeterCharacter(char character);
    void printCordinates() const;
    void draw() const;

    double getArea() const;
    double getPerimeter() const;
    double getWidth() const;
    double getLength() const;

    bool isSquare() const;

private:
    bool isValidateRectangle(const Coordinate& A, const Coordinate& B, const Coordinate& C, const Coordinate& D) const;
    double distance(const Coordinate& A, const Coordinate& B) const;
    double angleDot(const Coordinate& A, const Coordinate& B, const Coordinate& C) const;

    void setPointA(const Coordinate& A);
    void setPointB(const Coordinate& B);
    void setPointC(const Coordinate& C);
    void setPointD(const Coordinate& D);

private:
    Coordinate A_;
    Coordinate B_;
    Coordinate C_;
    Coordinate D_;
    char fillChar_;
    char perimeterChar_;
};

#endif /// __RECTANGLE_HPP__

