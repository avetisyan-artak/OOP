#ifndef __STRING_HPP__
#define __STRING_HPP__

#include <istream>
#include <ostream>

class String
{
    friend std::istream& operator>>(std::istream& input, String& string);
    friend std::ostream& operator<<(std::ostream& output, const String& string);

public:
    String(const char* string1 = "");
    String(const String& rhv);
    ~String();

    const String& operator=(const String& rhv);
    const String& operator+=(const String& rhv);

    bool operator>(const String& rhv)   const;
    bool operator>=(const String& rhv)  const;
    bool operator<(const String& rhv)   const;
    bool operator<=(const String& rhv)  const;
    bool operator==(const String& rhv)  const;
    bool operator!=(const String& rhv)  const;
    bool operator!()                    const;
    String operator+(const String& rhv) const;

    char& operator[](const int index);
    char  operator[](const int index) const;
    const String operator()(const int startIndex, const int lenght = 0) const;
    operator const char*() const;

    void setString(const char* string1);
    int getLength() const;

private:
    int lenght_;
    char* sPtr_;
};

#endif /// __STRING_HPP__

