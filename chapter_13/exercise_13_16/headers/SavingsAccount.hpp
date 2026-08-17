#ifndef __SAVINGS_ACCOUNT_HPP__
#define __SAVINGS_ACCOUNT_HPP__
#include "Account.hpp"

class SavingsAccount: public Account
{
public:
    SavingsAccount(const double balance = 0.0, const double percentage = 0.0);
    SavingsAccount(const SavingsAccount& rhv);
    virtual ~SavingsAccount() {}

    void setPercentage(const double percentage);
    double getPercentage() const;
    double calculateInterest() const;

    virtual void debit(const double amount);
    virtual void credit(const double amount);
    virtual void print() const;

private:
    double percentage_;
};

#endif /// __SAVINGS_ACCOUNT_HPP__

