#ifndef __PACKAGE_HPP__
#define __PACKAGE_HPP__
#include "Person.hpp"

class Package
{
public:
    Package(const Person& sender1, const Person& recipient1, double weight, double costPerOunce);
    Package(const Package& rhv);

    void setWeight(double weight);
    void setCostPerOunce(double costPerOnce);

    double getWeight() const;
    double getCostPerOunce() const;
    double calculateCost() const;

private:
    Person sender1_;
    Person recipient1_;
    double weight_;
    double costPerOunce_;
};

#endif /// __PACKAGE_HPP__

