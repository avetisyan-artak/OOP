#include "headers/CommissionEmployee.hpp"
#include "headers/BasePlusCommissionEmployee.hpp"
#include <iostream>
#include <cassert>

BasePlusCommissionEmployee::BasePlusCommissionEmployee(const std::string& name, const std::string& surName, const std::string& socialSecurityCode,
                                                       const double grossSales, const double baseSalary, const double rate)
    : commissionEmployee_(name, surName, socialSecurityCode, grossSales, rate)
    , baseSalary_(baseSalary)
{
}

BasePlusCommissionEmployee::BasePlusCommissionEmployee(const BasePlusCommissionEmployee& rhv)
    : commissionEmployee_(rhv.getName(), rhv.getSurname(), rhv.getSocialSecurityCode(),
                          rhv.getGrossSales(), rhv.getRate())
    , baseSalary_(rhv.getBaseSalary())
{
}

void
BasePlusCommissionEmployee::setName(const std::string& name)
{
    commissionEmployee_.setName(name);
}

void
BasePlusCommissionEmployee::setSurname(const std::string& surName)
{
    commissionEmployee_.setSurname(surName);
}

void
BasePlusCommissionEmployee::setSocialSecurityCode(const std::string& socialSecurityCode)
{
    commissionEmployee_.setSocialSecurityCode(socialSecurityCode);
}

void
BasePlusCommissionEmployee::setGrossSales(const double grossSales)
{
    commissionEmployee_.setGrossSales(grossSales);
}

void
BasePlusCommissionEmployee::setRate(const double rate)
{
    commissionEmployee_.setRate(rate);
}

void
BasePlusCommissionEmployee::setBaseSalary(const double baseSalary)
{
    assert(baseSalary >= 0);
    baseSalary_ = baseSalary;
}

const std::string&
BasePlusCommissionEmployee::getName() const
{
    return commissionEmployee_.getName();
}

const std::string&
BasePlusCommissionEmployee::getSurname() const
{
    return commissionEmployee_.getSurname();
}

const std::string&
BasePlusCommissionEmployee::getSocialSecurityCode() const
{
    return commissionEmployee_.getSocialSecurityCode();
}

double
BasePlusCommissionEmployee::getGrossSales() const
{
    return commissionEmployee_.getGrossSales();
}

double
BasePlusCommissionEmployee::getRate() const
{
    return commissionEmployee_.getRate();
}

double
BasePlusCommissionEmployee::getBaseSalary() const
{
    return baseSalary_;
}

double
BasePlusCommissionEmployee::salary() const
{
    return getBaseSalary() + commissionEmployee_.salary();
}

void BasePlusCommissionEmployee::print() const
{
    std::cout << "Base-Salaried Commission Employee Information:\n";
    commissionEmployee_.print();
    std::cout << "\nBase Salary: " << getBaseSalary() << '\n';
}

