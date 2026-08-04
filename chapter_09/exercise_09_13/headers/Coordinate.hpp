#ifndef __COORDINATE_HPP__
#define __COORDINATE_HPP__

const double MIN_VALUE_COORDINATE = 0.0;
const double MAX_VALUE_COORDINATE = 20.0;

class Coordinate
{
public:
    Coordinate(const Coordinate& rhv);
    Coordinate(const double x = 0.0, const double y = 0.0);

    void setX(const double x);
    void setY(const double y);

    double getX() const;
    double getY() const;

    void print() const;

private:
    double x_;
    double y_;
};

#endif /// __COORDINATE_HPP__

