#include "headers/Package.hpp"
#include <cassert>

Package::Package(const Person& sender1, const Person& recipient1, double weight, double costPerOunce)
    : sender1_(sender1)
    , recipient1_(recipient1)
{
    setWeight(weight);
    setCostPerOunce(costPerOunce);
}

Package::Package(const Package& rhv)
    : sender1_(rhv.sender1_)
    , recipient1_(rhv.recipient1_)
{
    setWeight(rhv.getWeight());
    setCostPerOunce(rhv.getCostPerOunce());
}

void
Package::setWeight(double weight)
{
    assert(weight >= 0);
    weight_ = weight;
}

void
Package::setCostPerOunce(double costPerOunce)
{
    assert(costPerOunce >= 0);
    costPerOunce_ = costPerOunce;
}

double
Package::getWeight() const
{
    return weight_;
}

double
Package::getCostPerOunce() const
{
    return costPerOunce_;
}

double
Package::calculateCost() const
{
    return weight_ * costPerOunce_;
}

void
Package::print() const
{
    std::cout << "Sender:" << std::endl;
    std::cout << "  " << sender1_.getName() << std::endl;
    std::cout << "  " << sender1_.getAddress() << std::endl;
    std::cout << "  " << sender1_.getCity() << ", " 
              << sender1_.getState() << " " 
              << sender1_.getZIP() << std::endl;

    std::cout << "Recipient:" << std::endl;
    std::cout << "  " << recipient1_.getName() << std::endl;
    std::cout << "  " << recipient1_.getAddress() << std::endl;
    std::cout << "  " << recipient1_.getCity() << ", " 
              << recipient1_.getState() << " " 
              << recipient1_.getZIP() << std::endl;

    std::cout << "Weight: " << weight_ << " oz" << std::endl;
    std::cout << "Cost per ounce: $" << costPerOunce_ << std::endl;
    std::cout << "Shipping cost: $" << calculateCost() << std::endl;
}

