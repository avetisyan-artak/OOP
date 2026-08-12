#ifndef __DOUBLE_SUBSCRIPTED_ARRAY_HPP__
#define __DOUBLE_SUBSCRIPTED_ARRAY_HPP__

#include <iostream>

class DoubleSubscriptedArray
{
    friend std::istream& operator>>(std::istream& input, DoubleSubscriptedArray& obj);
    friend std::ostream& operator<<(std::ostream& output, const DoubleSubscriptedArray& obj);

public:
    DoubleSubscriptedArray(const int row = 1, const int column = 1);
    DoubleSubscriptedArray(const DoubleSubscriptedArray& rhv);
    ~DoubleSubscriptedArray();

    DoubleSubscriptedArray& operator=(const DoubleSubscriptedArray& rhv);

    int& operator()(const int row, const int column);
    int  operator()(const int row, const int column)   const;
    bool operator==(const DoubleSubscriptedArray& rhv) const;
    bool operator!=(const DoubleSubscriptedArray& rhv) const;

    int getRow()    const;
    int getColumn() const;
    int getSize()   const;

    void setRow(const int row);
    void setColumn(const int column);
    void sort();

private:
    int row_;
    int column_;
    int* array_;
};

#endif /// __DOUBLE_SUBSCRIPTED_ARRAY_HPP__

