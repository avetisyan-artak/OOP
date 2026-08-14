#ifndef __TWO_DAY_PACKAGE_HPP__
#define __TWO_DAY_PACKAGE_HPP__
#include "Package.hpp"

class TwoDayPackage: public Package
{
public:
    TwoDayPackage(const Person& sender1, const Person& recipient1, double weight, double costPerOunce, double flatFee);
    TwoDayPackage(const TwoDayPackage& rhv);

    void setFlatFee(double flatFee);
    double getFlatFee() const;
    double calculateCost() const;

private:
    double flatFee_;
};

#endif /// __TWO_DAY_PACKAGE_HPP__

