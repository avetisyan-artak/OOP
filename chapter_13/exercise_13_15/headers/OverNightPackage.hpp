#ifndef OVER_NIGHT_PACKAGE_HPP
#define OVER_NIGHT_PACKAGE_HPP
#include "Package.hpp"

class OverNightPackage: public Package
{
public:
    OverNightPackage(const Person& sender, const Person& recipient, double weight, double costPerOunce, double extraCost);
    OverNightPackage(const OverNightPackage& rhv);
    virtual ~OverNightPackage() {};

    void setExtraCost(double extraCost);
    double getExtraCost() const;

    virtual double calculateCost() const;
    virtual void print() const;

private:
    double extraCost_;
};

#endif /// OVER_NIGHT_PACKAGE_HPP

