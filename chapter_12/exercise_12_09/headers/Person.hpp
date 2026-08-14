#ifndef __PERSON_HPP__
#define __PERSON_HPP__
#include <iostream>
#include <string>

class Person
{
    friend std::istream& operator>>(std::istream& input, Person& person);
    friend std::ostream& operator<<(std::ostream& output, const Person& person);

public:
    Person(const std::string& name, const std::string& address, const std::string& cityName,
           const std::string& stateName, const std::string& ZIP);
    Person(const Person& rhv);

    void setName(const std::string& name);
    void setAddress(const std::string& address);
    void setCityName(const std::string& cityName);
    void setStateName(const std::string& stateName);
    void setZIP(const std::string& ZIP);

    const std::string& getName() const;
    const std::string& getAddress() const;
    const std::string& getCityName() const;
    const std::string& getStateName() const;
    const std::string& getZIP() const;

private:
    std::string name_;
    std::string address_;
    std::string cityName_;
    std::string stateName_;
    std::string zip_;
};

#endif /// __PERSON_HPP__

