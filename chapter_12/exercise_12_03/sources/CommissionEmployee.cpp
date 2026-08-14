#include "headers/CommissionEmployee.hpp"
#include <iostream>
#include <cassert>

CommissionEmployee::CommissionEmployee(const std::string& name, const std::string& surName, const std::string& socialSecurityCode,
                                       const double grossSales, const double rate)
    : name_(name)
    , surName_(surName)
    , socialSecurityCode_(socialSecurityCode)
    , grossSales_(grossSales)
    , rate_(rate)
{
}

CommissionEmployee::CommissionEmployee(const CommissionEmployee& rhv)
    : name_(rhv.name_)
    , surName_(rhv.surName_)
    , socialSecurityCode_(rhv.socialSecurityCode_)
    , grossSales_(rhv.grossSales_)
    , rate_(rhv.rate_)
{
}

void
CommissionEmployee::setName(const std::string& name)
{
    name_ = name;
}

void
CommissionEmployee::setSurname(const std::string& surName)
{
    surName_ = surName;
}

void
CommissionEmployee::setSocialSecurityCode(const std::string& socialSecurityCode)
{
    socialSecurityCode_ = socialSecurityCode;
}

void
CommissionEmployee::setGrossSales(const double grossSales)
{
    assert(grossSales >= 0);
    grossSales_ = grossSales;
}

void
CommissionEmployee::setRate(const double rate)
{
    assert(rate >= 0);
    rate_ = rate;
}

double
CommissionEmployee::salary() const
{
    return getRate() * getGrossSales();

}

const std::string&
CommissionEmployee::getName() const
{
    return name_;
}

const std::string&
CommissionEmployee::getSurname() const
{
    return surName_;
}

const std::string&
CommissionEmployee::getSocialSecurityCode() const
{
    return socialSecurityCode_;
}

double
CommissionEmployee::getGrossSales() const
{
    return grossSales_;
}

double
CommissionEmployee::getRate() const
{
    return rate_;
}

void
CommissionEmployee::print() const
{
    std::cout << "Commission Employee Information:\n"
              << "Name: "                   << getName() << ' ' << getSurname() << '\n'
              << "Social Security Number: " << getSocialSecurityCode() << '\n'
              << "Gross Sales: "            << getGrossSales() << '\n'
              << "Commission Rate: "        << getRate() << '\n';
}

