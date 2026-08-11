#include "headers/String.hpp"
#include <iostream>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <cstdlib>

String::String(const char* string1)
    : lenght_((string1 != NULL) ? std::strlen(string1) : 0)
    , sPtr_(NULL)
{
    setString(string1);
}

String::String(const String& rhv)
    : lenght_(rhv.lenght_)
    , sPtr_(NULL)
{
    setString(rhv.sPtr_);
}

String::~String()
{
    if (sPtr_ != NULL) {
        delete[] sPtr_;
        sPtr_ = NULL;
    }
}

bool
String::operator>(const String& rhv) const
{
    return rhv < *this;
}

bool
String::operator>=(const String& rhv) const
{
    return !(*this < rhv);
}

bool
String::operator<(const String& rhv) const
{
    return std::strcmp(sPtr_, rhv.sPtr_) < 0;
}

bool
String::operator<=(const String& rhv) const
{
    return !(*this > rhv);
}

bool
String::operator==(const String& rhv) const
{
    return std::strcmp(sPtr_, rhv.sPtr_) == 0;
}

bool
String::operator!=(const String& rhv) const
{
    return !(*this == rhv);
}

bool
String::operator!() const
{
    return (0 == getLength());
}

String
String::operator+(const String& rhv) const
{
    const size_t newSize = lenght_ + rhv.lenght_;
    String temp;

    temp.lenght_ = newSize;
    temp.sPtr_ = new char[newSize + 1];

    if (sPtr_ != NULL) std::strcpy(temp.sPtr_, sPtr_);
    if (rhv.sPtr_ != NULL) std::strcpy(temp.sPtr_ + lenght_, rhv.sPtr_);
    return temp;
}

const String&
String::operator+=(const String& rhv)
{
    const size_t newLength = lenght_ + rhv.lenght_;
    char* temp = new char[newLength + 1];

    if (sPtr_ != NULL) std::strcpy(temp, sPtr_);
    if (rhv.sPtr_ != NULL)  std::strcpy(temp + lenght_, rhv.sPtr_);

    delete[] sPtr_;
    sPtr_ = temp;
    lenght_ = newLength;
    return *this;
}

const String&
String::operator=(const String& rhv)
{
    if (this == &rhv) return *this;

    if (getLength() == rhv.getLength()) {
        std::strcpy(sPtr_, rhv.sPtr_);
        return *this;
    }
    delete[] sPtr_;
    lenght_ = rhv.getLength();
    setString(rhv.sPtr_);
    return *this;
}

void
String::setString(const char* string1)
{
    if (0 == getLength()) return;
    sPtr_ = new char[getLength() + 1];
    std::strcpy(sPtr_, string1);
}

std::ostream&
operator<<(std::ostream& output, const String& string1)
{
    output << string1.sPtr_;
    return output;
}

std::istream&
operator>>(std::istream& input, String& string1)
{
    char temp[100];
    input >> std::setw(100) >> temp;
    string1 = temp;
    return input;
}

const String
String::operator()(const int startIndex, const int length) const
{
    assert(startIndex >= 0 && startIndex < getLength() && length >= 0 && length < getLength());
    const int stringLength = (((0 == length) || (startIndex + length > getLength())) ? (getLength() - startIndex) : length);

    String tempString("");
    tempString.lenght_ = stringLength + 1;
    tempString.sPtr_ = new char[stringLength + 1];
    std::strncpy(tempString.sPtr_, &sPtr_[startIndex], stringLength);
    tempString[stringLength] = '\0';
    return tempString;
}

char&
String::operator[](const int index)
{
    assert(index >= 0 && index < getLength());
    return sPtr_[index];
}

char
String::operator[](const int index) const
{
    assert(index >= 0 && index < getLength());
    return sPtr_[index];
}

int
String::getLength() const
{
    return lenght_;
}

String::operator const char*() const
{
    return sPtr_;
}

