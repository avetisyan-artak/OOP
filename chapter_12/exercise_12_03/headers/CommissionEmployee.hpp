#ifndef __COMMISSION_EMPLOYEE_HPP__
#define __COMMISSION_EMPLOYEE_HPP__
#include <string>

class CommissionEmployee
{
public:
    CommissionEmployee(const std::string& name, const std::string& surName, const std::string& socialSecurityCode,
                       const double grossSales = 0.0, const double rate = 0.0);
    CommissionEmployee(const CommissionEmployee& rhv);

    void setName(const std::string& name);
    void setSurname(const std::string& surName);
    void setSocialSecurityCode(const std::string& socialSecurityCode);
    void setGrossSales(const double grossSales);
    void setRate(const double rate);
    void print() const;

    const std::string& getName() const;
    const std::string& getSurname() const;
    const std::string& getSocialSecurityCode() const;
    double getGrossSales() const;
    double getRate() const;
    double salary() const;

private:
    std::string name_;
    std::string surName_;
    std::string socialSecurityCode_;
    double grossSales_;
    double rate_;
};

#endif /// __COMMISSION_EMPLOYEE_HPP__

