#ifndef TWO_DAY_PACKAGE_HPP
#define TWO_DAY_PACKAGE_HPP
#include "Package.hpp"

class TwoDayPackage: public Package
{
public:
    TwoDayPackage(const Person& sender1, const Person& recipient1, double weight, double costPerOunce, double flatFee);
    virtual ~TwoDayPackage() {};
    TwoDayPackage(const TwoDayPackage& rhv);

    void setFlatFee(double flatFee);
    double getFlatFee() const;

    virtual double calculateCost() const;
    virtual void print() const;

private:
    double flatFee_;
};

#endif /// TWO_DAY_PACKAGE_HPP

