#ifndef __INTEGER_SET_HPP__
#define __INTEGER_SET_HPP__

const int SIZE = 101;

class IntegerSet
{
public:
    IntegerSet();
    IntegerSet(const IntegerSet& rhv);
    IntegerSet(const int array[], const int size);

    IntegerSet unionOfSets(const IntegerSet& rhv);
    IntegerSet insertSectionOfSets(const IntegerSet& rhv);

    void insert(const int number1);
    void deleteElement(const int number1);
    void printSet() const;

    bool isEqualTo(const IntegerSet& rhv) const;

private:
    void init();

private:
    bool array_[SIZE];
};

#endif /// __INTEGER_SET_HPP__

