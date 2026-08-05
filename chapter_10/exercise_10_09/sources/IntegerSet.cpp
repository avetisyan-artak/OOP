#include "headers/IntegerSet.hpp"
#include <iostream>
#include <cassert>

IntegerSet::IntegerSet()
{
    init();
}

IntegerSet::IntegerSet(const IntegerSet& rhv)
{
    for (int i = 0; i < SIZE; ++i) {
        array_[i] = rhv.array_[i];
    }
}

IntegerSet::IntegerSet(const int array[], const int size)
{
    for (int i = 0; i < SIZE; ++i) {
        array_[i] = 0;
    }

    for (int i = 0; i < size; ++i) {
        if (array[i] >= 0 && array[i] < SIZE) {
            array_[array[i]] = 1;
        }
    }
}

void
IntegerSet::init()
{
    for (int i = 0; i < SIZE; ++i) {
        array_[i] = false;
    }
}

IntegerSet
IntegerSet::unionOfSets(const IntegerSet& rhv)
{
    IntegerSet result;

    for (int i = 0; i < SIZE; ++i) {
        result.array_[i] = array_[i] || rhv.array_[i];
    }
    return result;
}

IntegerSet
IntegerSet::insertSectionOfSets(const IntegerSet& rhv)
{
    IntegerSet result;

    for (int i = 0; i < SIZE; ++i) {
        result.array_[i] = array_[i] && rhv.array_[i];
    }
    return result;
}

void
IntegerSet::insert(const int number1)
{
    assert(number1 >= 0 && number1 < SIZE);
    array_[number1] = true;
}

void
IntegerSet::deleteElement(const int number1)
{
    assert(number1 >= 0 && number1 < SIZE);
    array_[number1] = false;
}

bool
IntegerSet::isEqualTo(const IntegerSet& rhv) const
{
    for (int i = 0; i < SIZE; ++i) {
        if (array_[i] != rhv.array_[i]) {
            return false;
        }
    }
    return true;
}

void
IntegerSet::printSet() const
{
    bool hasNumbers = true;

    for (int i = 0; i < SIZE; ++i) {
        if (array_[i]) {
            std::cout << i << " " << std::endl;
            hasNumbers = false;
        }
    }

    if (hasNumbers) {
        std::cout << "----" << std::endl;
    }
    std::cout << std::endl;
}

