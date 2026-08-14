#ifndef __BASE_PLUS_COMMISSION_EMPLOYEE_HPP__
#define __BASE_PLUS_COMMISSION_EMPLOYEE_HPP__

class BasePlusCommissionEmployee
{
public:
    BasePlusCommissionEmployee(const std::string& name, const std::string& surname, const std::string& socialSecurityCode,
                               const double grossSales = 0.0, const double baseSalary = 0.0, const double rate = 0.0);
    BasePlusCommissionEmployee(const BasePlusCommissionEmployee& rhv);

    void setName(const std::string& name);
    void setSurname(const std::string& surName);
    void setSocialSecurityCode(const std::string& securityCode);
    void setGrossSales(const double grossSales);
    void setBaseSalary(const double baseSalary);
    void setRate(const double rate);
    void print() const;

    const std::string& getName() const;
    const std::string& getSurname() const;
    const std::string& getSocialSecurityCode() const;
    double getGrossSales() const;
    double getBaseSalary() const;
    double getRate() const;
    double salary() const;

private:
    CommissionEmployee commissionEmployee_;
    double baseSalary_;
};

#endif /// __BASE_PLUS_COMMISSION_EMPLOYEE_HPP__

