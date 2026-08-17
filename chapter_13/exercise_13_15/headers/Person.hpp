#ifndef __PERSON_HPP__
#define __PERSON_HPP__
#include <iostream>
#include <string>

class Person
{
    friend std::istream& operator>>(std::istream& input, Person& person);
    friend std::ostream& operator<<(std::ostream& output, const Person& person);

public:
    Person(const std::string& name = "Alex", const std::string& address = "642", const std::string& city = "Los Angeles",
           const std::string& state = "California", const std::string& zip = "9090");
    Person(const Person& rhv);

    void setName(const std::string& name);
    void setAddress(const std::string& address);
    void setCity(const std::string& cityName);
    void setState(const std::string& stateName);
    void setZIP(const std::string& zip);

    const std::string& getName()    const;
    const std::string& getAddress() const;
    const std::string& getCity()    const;
    const std::string& getState()   const;
    const std::string& getZIP()     const;

private:
    std::string name_;
    std::string address_;
    std::string cityName_;
    std::string stateName_;
    std::string zip_;
};

#endif /// __PERSON_HPP__

