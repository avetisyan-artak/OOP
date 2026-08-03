#ifndef __RECTANGLE_HPP__
#define __RECTANGLE_HPP__

class Rectangle
{
public:
    Rectangle();
    Rectangle(const double length, const double width);
    Rectangle(const Rectangle& rhv);

    bool setLength(double length);
    bool setWidth(double width);

    double getLength() const;
    double getWidth() const;

    double getPerimeter() const;
    double getArea() const;

    void printResult() const;

private:
    double length_;
    double width_;
};

#endif /// __RECTANGLE_HPP__

