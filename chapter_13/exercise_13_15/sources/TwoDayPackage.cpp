#include "headers/TwoDayPackage.hpp"

TwoDayPackage::TwoDayPackage(const Person& sender, const Person& recipient, double weight, double costPerOunce, double flatFee)
    : Package(sender, recipient, weight, costPerOunce)
    , flatFee_(flatFee)
{
}

TwoDayPackage::TwoDayPackage(const TwoDayPackage& rhv)
    : Package(rhv)
    , flatFee_(rhv.flatFee_)
{
}

void
TwoDayPackage::setFlatFee(double flatFee)
{
    flatFee_ = flatFee;
}

double
TwoDayPackage::getFlatFee() const
{
    return flatFee_;
}

double
TwoDayPackage::calculateCost() const
{
    return Package::calculateCost() + flatFee_;
}

void
TwoDayPackage::print() const
{
    std::cout << "Two-Day Package:" << std::endl;
    Package::print();
    std::cout << "Flat fee: $" << flatFee_ << std::endl;
    std::cout << "Total cost: $" << calculateCost() << std::endl;
}

