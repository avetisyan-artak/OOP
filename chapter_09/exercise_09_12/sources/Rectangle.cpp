#include "../headers/Rectangle.hpp"
#include <iostream>
#include <cassert>
#include <cmath>

Rectangle::Rectangle()
{
    p1_.x = 0.0;
    p1_.y = 0.0;

    p2_.x = 0.0;
    p2_.y = 0.0;

    p3_.x = 0.0;
    p3_.y = 0.0;

    p4_.x = 0.0;
    p4_.y = 0.0;
}

Rectangle::Rectangle(const Point& p1, const Point& p2,
                     const Point& p3, const Point& p4)
{
    setPoint1(p1);
    setPoint2(p2);
    setPoint3(p3);
    setPoint4(p4);
}

Rectangle::Rectangle(const Rectangle& rhv)
{
    setPoint1(rhv.p1_);
    setPoint2(rhv.p2_);
    setPoint3(rhv.p3_);
    setPoint4(rhv.p4_);
}

void
Rectangle::setPoint1(const Point& p1)
{
    assert(p1.x >= 0.0 && p1.x <= MAX_COORD);
    assert(p1.y >= 0.0 && p1.y <= MAX_COORD);
    p1_ = p1;
}

void
Rectangle::setPoint2(const Point& p2)
{
    assert(p2.x >= 0.0 && p2.x <= MAX_COORD);
    assert(p2.y >= 0.0 && p2.y <= MAX_COORD);
    p2_ = p2;
}

void
Rectangle::setPoint3(const Point& p3)
{
    assert(p3.x >= 0.0 && p3.x <= MAX_COORD);
    assert(p3.y >= 0.0 && p3.y <= MAX_COORD);
    p3_ = p3;
}

void
Rectangle::setPoint4(const Point& p4)
{
    assert(p4.x >= 0.0 && p4.x <= MAX_COORD);
    assert(p4.y >= 0.0 && p4.y <= MAX_COORD);
    p4_ = p4;
}


Point
Rectangle::getPoint1()
{
    return p1_;
}

Point
Rectangle::getPoint2()
{
    return p2_;
}

Point
Rectangle::getPoint3()
{
    return p3_;
}

Point
Rectangle::getPoint4()
{
    return p4_;
}

double
Rectangle::distance(const Point& a, const Point& b)
{
    const double dx = a.x - b.x;
    const double dy = a.y - b.y;

    return std::sqrt(dx * dx + dy * dy);
}

double
Rectangle::angleDot(const Point& a, const Point& b, const Point& c)
{
    const double abx = b.x - a.x;
    const double aby = b.y - a.y;

    const double bcx = c.x - b.x;
    const double bcy = c.y - b.y;

    return abx * bcx + aby * bcy;
}

bool
Rectangle::isValidateRectangle()
{
    const double d1 = distance(p1_, p2_);
    const double d2 = distance(p2_, p3_);
    const double d3 = distance(p3_, p4_);
    const double d4 = distance(p4_, p1_);

    const bool oppositeSidesEqual =
        std::fabs(d1 - d3) < EPSILION &&
        std::fabs(d2 - d4) < EPSILION;


    const bool rightAngles =
        std::fabs(angleDot(p1_, p2_, p3_)) < EPSILION &&
        std::fabs(angleDot(p2_, p3_, p4_)) < EPSILION &&
        std::fabs(angleDot(p3_, p4_, p1_)) < EPSILION &&
        std::fabs(angleDot(p4_, p1_, p2_)) < EPSILION;


    return oppositeSidesEqual && rightAngles;
}

double
Rectangle::getLength()
{
    const double d1 = distance(p1_, p2_);
    const double d2 = distance(p2_, p3_);

    return (d1 > d2 ? d1 : d2);
}

double
Rectangle::getWidth()
{
    const double d1 = distance(p1_, p2_);
    const double d2 = distance(p2_, p3_);

    return (d1 < d2 ? d1 : d2);
}

double
Rectangle::getPerimeter()
{
    return 2 * (getLength() + getWidth());
}

double
Rectangle::getArea()
{
    return getLength() * getWidth();
}

bool
Rectangle::isSquare()
{
    return std::fabs(getLength() - getWidth()) < EPSILION;
}

void
Rectangle::printCordinates()
{
    std::cout << "Rectangle coordinates:\n"
              << "(" << p1_.x << "," << p1_.y << ")\n"
              << "(" << p2_.x << "," << p2_.y << ")\n"
              << "(" << p3_.x << "," << p3_.y << ")\n"
              << "(" << p4_.x << "," << p4_.y << ")\n"
              << std::endl;
}

