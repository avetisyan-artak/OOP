#ifndef __OVER_NIGHT_PACKAGE_HPP__
#define __OVER_NIGHT_PACKAGE_HPP__
#include "Package.hpp"

class OverNightPackage: public Package
{
public:
    OverNightPackage(const Person& sender1, const Person& recipient1, double weight, double costPerOunce, double extraCost);
    OverNightPackage(const OverNightPackage& rhv);

    void setExtraCost(double extraCost);
    double getExtraCost() const;
    double calculateCost() const;

private:
    double extraCost_;
};

#endif /// __OVER_NIGHT_PACKAGE_HPP__

