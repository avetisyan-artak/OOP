#ifndef __RECTANGLE_HPP__
#define __RECTANGLE_HPP__

const double EPSILION = 1e-9;
const double MAX_COORD = 20.0;

struct Point
{
    double x;
    double y;
};

class Rectangle
{
public:
    Rectangle();
    Rectangle(const Point& p1, const Point& p2, const Point& p3, const Point& p4);
    Rectangle(const Rectangle& rhv);

    void printCordinates();

    void setPoint1(const Point& p1);
    void setPoint2(const Point& p2);
    void setPoint3(const Point& p3);
    void setPoint4(const Point& p4);

    Point getPoint1();
    Point getPoint2();
    Point getPoint3();
    Point getPoint4();
    double getArea();
    double getPerimeter();
    double getWidth();
    double getLength();

    bool isSquare();

private:
    bool isValidateRectangle();
    double distance(const Point& a, const Point& b);
    double angleDot(const Point& a, const Point& b, const Point& c);

private:
    Point p1_;
    Point p2_;
    Point p3_;
    Point p4_;
};

#endif ///__RECTANGLE_HPP__

