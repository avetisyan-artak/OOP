#ifndef __PACKAGE_HPP__
#define __PACKAGE_HPP__
#include "Person.hpp"

class Package
{
public:
    Package(const Person& sender1, const Person& recipient1, double weight, double costPerOunce);
    Package(const Package& rhv);
    virtual ~Package() {}

    void setWeight(double weight);
    double getWeight() const;

    void setCostPerOunce(double costPerOunce);
    double getCostPerOunce() const;

    virtual double calculateCost() const;
    virtual void print() const;

private:
    Person sender1_;
    Person recipient1_;
    double weight_;
    double costPerOunce_;
};

#endif /// PACKAGE_HPP

