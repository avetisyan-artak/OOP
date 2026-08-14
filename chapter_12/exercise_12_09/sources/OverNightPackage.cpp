#include "headers/OverNightPackage.hpp"

OverNightPackage::OverNightPackage(const Person& sender1, const Person& recipient1, double weight, double costPerOunce, double extraCost)
    : Package(sender1, recipient1, weight, costPerOunce)
    , extraCost_(extraCost)
{}

OverNightPackage::OverNightPackage(const OverNightPackage& rhv)
    : Package(rhv)
    , extraCost_(rhv.extraCost_)
{}

void
OverNightPackage::setExtraCost(double extraCost)
{
    extraCost_ = extraCost;
}

double
OverNightPackage::getExtraCost() const
{
    return extraCost_;
}

double
OverNightPackage::calculateCost() const
{
    return Package::calculateCost() + extraCost_;
}

