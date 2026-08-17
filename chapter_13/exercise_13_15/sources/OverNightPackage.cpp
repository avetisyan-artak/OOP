#include "headers/OverNightPackage.hpp"

OverNightPackage::OverNightPackage(const Person& sender, const Person& recipient, double weight, double costPerOunce, double extraCost)
    : Package(sender, recipient, weight, costPerOunce)
    , extraCost_(extraCost)
{
}

OverNightPackage::OverNightPackage(const OverNightPackage& rhv)
    : Package(rhv)
    , extraCost_(rhv.extraCost_)
{
}

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

void
OverNightPackage::print() const
{
    std::cout << "Overnight Package:" << std::endl;
    Package::print();
    std::cout << "Extra cost: $" << extraCost_ << std::endl;
    std::cout << "Total cost: $" << calculateCost() << std::endl;
}

