#include "../headers/Rectangle.hpp"
#include <iostream>
#include <cctype>
#include <cmath>
#include <cassert>

Rectangle::Rectangle(const Coordinate& A, const Coordinate& B,
                     const Coordinate& C, const Coordinate& D,
                     const char fill, const char perimeter)
{
    setPointA(A);
    setPointB(B);
    setPointC(C);
    setPointD(D);
    setFillCharacter(fill);
    setPerimeterCharacter(perimeter);
}

Rectangle::Rectangle(const Rectangle& rhv)
    : A_(rhv.A_)
    , B_(rhv.B_)
    , C_(rhv.C_)
    , D_(rhv.D_)
    , fillChar_(rhv.fillChar_)
    , perimeterChar_(rhv.perimeterChar_)
{
}

void
Rectangle::setPointA(const Coordinate& A)
{
    A_ = A;
}

void
Rectangle::setPointB(const Coordinate& B)
{
    B_ = B;
}

void
Rectangle::setPointC(const Coordinate& C)
{
    C_ = C;
}

void
Rectangle::setPointD(const Coordinate& D)
{
    D_ = D;
}

Coordinate
Rectangle::getPointA() const
{
    return A_;
}

Coordinate
Rectangle::getPointB() const
{
    return B_;
}

Coordinate
Rectangle::getPointC() const
{
    return C_;
}

Coordinate
Rectangle::getPointD() const
{
    return D_;
}

double
Rectangle::distance(const Coordinate& A, const Coordinate& B) const
{
    const double dx = A.getX() - B.getX();
    const double dy = A.getY() - B.getY();

    return std::sqrt(dx * dx + dy * dy);
}

double
Rectangle::angleDot(const Coordinate& A,
                    const Coordinate& B,
                    const Coordinate& C) const
{
    const double x1 = A.getX() - B.getX();
    const double y1 = A.getY() - B.getY();

    const double x2 = C.getX() - B.getX();
    const double y2 = C.getY() - B.getY();

    return x1 * x2 + y1 * y2;
}

double
Rectangle::getLength() const
{
    const double firstSide = distance(A_, B_);
    const double secondSide = distance(B_, C_);

    return (firstSide > secondSide) ? firstSide : secondSide;
}

double
Rectangle::getWidth() const
{
    const double firstSide = distance(A_, B_);
    const double secondSide = distance(B_, C_);

    return (firstSide < secondSide) ? firstSide : secondSide;
}

double
Rectangle::getPerimeter() const
{
    return 2 * (getLength() + getWidth());
}

double
Rectangle::getArea() const
{
    return getLength() * getWidth();
}

bool
Rectangle::isSquare() const
{
    return std::fabs(getLength() - getWidth()) < EPSILON;
}

void
Rectangle::printCordinates() const
{
    std::cout << "Rectangle coordinates:\n"
              << "(" << A_.getX() << "," << A_.getY() << ")\n"
              << "(" << B_.getX() << "," << B_.getY() << ")\n"
              << "(" << C_.getX() << "," << C_.getY() << ")\n"
              << "(" << D_.getX() << "," << D_.getY() << ")\n";
}

void
Rectangle::draw() const
{
    const Coordinate* coordinates[] = {&A_, &B_, &C_, &D_};

    const Coordinate* maxX = coordinates[0];
    const Coordinate* minX = coordinates[0];
    const Coordinate* maxY = coordinates[0];
    const Coordinate* minY = coordinates[0];


    for (int i = 1; i < COUNT_OF_TOP; ++i) {

        if (maxX->getX() < coordinates[i]->getX()) {
            maxX = coordinates[i];
        }

        if (minX->getX() > coordinates[i]->getX()) {
            minX = coordinates[i];
        }

        if (maxY->getY() < coordinates[i]->getY()) {
            maxY = coordinates[i];
        }

        if (minY->getY() > coordinates[i]->getY()) {
            minY = coordinates[i];
        }
    }


    for (int y = SIZE_CORD; y >= 0; --y) {

        for (int x = 0; x <= SIZE_CORD; ++x) {

            if (x >= minX->getX() &&
                x <= maxX->getX() &&
                y >= minY->getY() &&
                y <= maxY->getY()) {

                std::cout << getFillCharacter();
            }
            else {
                std::cout << ' ';
            }
        }

        std::cout << std::endl;
    }
}


char
Rectangle::getFillCharacter() const
{
    return fillChar_;
}


char
Rectangle::getPerimeterCharacter() const
{
    return perimeterChar_;
}


void
Rectangle::setPerimeterCharacter(const char perimeter)
{
    assert(std::isprint(static_cast<unsigned char>(perimeter)));
    perimeterChar_ = perimeter;
}


void
Rectangle::setFillCharacter(const char fill)
{
    assert(std::isprint(static_cast<unsigned char>(fill)));
    fillChar_ = fill;
}

