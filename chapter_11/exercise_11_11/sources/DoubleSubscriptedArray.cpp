#include "headers/DoubleSubscriptedArray.hpp"
#include <cassert>
#include <iomanip>

DoubleSubscriptedArray::DoubleSubscriptedArray(const int row, const int column)
    : row_(0)
    , column_(0)
    , array_(NULL)
{
    setRow(row);
    setColumn(column);
    const int size = getSize();
    array_ = new int[size]();
}

DoubleSubscriptedArray::DoubleSubscriptedArray(const DoubleSubscriptedArray& rhv)
{
    setRow(rhv.getRow());
    setColumn(rhv.getColumn());
    array_ = new int[getSize()];
    for (int i = 0; i < getSize(); ++i) {
        array_[i] = rhv.array_[i];
    }
}

DoubleSubscriptedArray::~DoubleSubscriptedArray()
{
    if (NULL != array_) {
        delete[] array_;
        array_ = NULL;
    }
}

int&
DoubleSubscriptedArray::operator()(const int row, const int column)
{
    assert(row >= 0 && column >= 0);
    return array_[row * getColumn() + column];
}

int
DoubleSubscriptedArray::operator()(const int row, const int column) const
{
    assert(row >= 0 && column >= 0);
    return array_[row * getColumn() + column];
}

bool
DoubleSubscriptedArray::operator==(const DoubleSubscriptedArray& rhv) const
{
    if (this == &rhv) return true;
    if ((getRow() != rhv.getRow()) || getColumn() != rhv.getColumn()) return false;
    for (int i = 0; i < getSize(); ++i) {
        if (array_[i] != rhv.array_[i]) return false;
    }
    return true;
}

bool
DoubleSubscriptedArray::operator!=(const DoubleSubscriptedArray& rhv) const
{
    return !(*this == rhv);
}

int
DoubleSubscriptedArray::getRow() const
{
    return row_;
}

int
DoubleSubscriptedArray::getColumn() const
{
    return column_;
}

int
DoubleSubscriptedArray::getSize() const
{
    return getRow() * getColumn();
}

void
DoubleSubscriptedArray::setRow(const int row)
{
    assert(row >= 0);
    row_ = row;
}

void
DoubleSubscriptedArray::setColumn(const int column)
{
    assert(column >= 0);
    column_ = column;
}

void
DoubleSubscriptedArray::sort()
{
    const int size = getSize() - 1;
    bool isSorted = false;

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size - i; ++j) {
            if (*(array_ + j) < *(array_ + j + 1)) {
                isSorted = false;
                std::swap(*(array_ + j), *(array_ + j + 1));
            }
        }
        if (isSorted) break;
    }
}

std::istream&
operator>>(std::istream& input, DoubleSubscriptedArray& rhv)
{
    for (int i = 0; i < rhv.getSize(); ++i) {
        input >> rhv.array_[i];
    }
    return input;
}

std::ostream&
operator<<(std::ostream& output, const DoubleSubscriptedArray& rhv)
{
    for (int i = 0; i < rhv.getRow(); ++i) {
        for (int j = 0; j < rhv.getColumn(); ++j) {
            output << std::setw(5) << rhv(i, j);
        }
        output << '\n';
    }
    return output;
}

DoubleSubscriptedArray&
DoubleSubscriptedArray::operator=(const DoubleSubscriptedArray& rhv)
{
    if (*this == rhv) return *this;
    delete[] array_;
    setRow(rhv.getRow());
    setColumn(rhv.getColumn());
    array_ = new int[getSize()];
    for (int i = 0; i < getSize(); ++i) {
        array_[i] = rhv.array_[i];
    }
    return *this;
}

