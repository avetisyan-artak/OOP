#include "headers/Person.hpp"

Person::Person(const std::string& name, const std::string& address, const std::string& cityName,
               const std::string& stateName, const std::string& ZIP)
    : name_(name)
    , address_(address)
    , cityName_(cityName)
    , stateName_(stateName)
    , zip_(ZIP)
{
}

Person::Person(const Person& rhv)
    : name_(rhv.name_)
    , address_(rhv.address_)
    , cityName_(rhv.cityName_)
    , stateName_(rhv.stateName_)
    , zip_(rhv.zip_)
{
}

void
Person::setName(const std::string& name)
{
    name_ = name;
}

void
Person::setAddress(const std::string& address)
{
    address_ = address;
}

void
Person::setCity(const std::string& cityName)
{
    cityName_ = cityName;
}

void
Person::setState(const std::string& stateName)
{
    stateName_ = stateName;
}

void
Person::setZIP(const std::string& ZIP)
{
    zip_ = ZIP;
}

const std::string&
Person::getName() const
{
    return name_;
}

const std::string&
Person::getAddress() const
{
    return address_;
}

const std::string&
Person::getCity() const
{
    return cityName_;
}

const std::string&
Person::getState() const
{
    return stateName_;
}

const std::string&
Person::getZIP() const
{
    return zip_;
}

std::istream&
operator>>(std::istream& input, Person& person)
{
    input >> person.name_ >> person.address_ >> person.cityName_ >> person.stateName_ >> person.zip_;
    return input;
}

std::ostream&
operator<<(std::ostream& output, const Person& person)
{
    output << person.name_ << ' '
           << person.address_ << ' '
           << person.cityName_ << ' '
           << person.stateName_ << ' '
           << person.zip_;
    return output;
}

