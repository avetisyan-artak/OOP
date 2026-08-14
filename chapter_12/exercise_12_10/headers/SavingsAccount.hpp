#ifndef __SAVING_ACCOUNT_HPP__
#define __SAVING_ACCOUNT_HPP__
#include "headers/Account.hpp"

class SavingAccount: public Account
{
public:
    SavingAccount(const double initialBalance = 0.0, const double percentage = 0.0);
    SavingAccount(const SavingAccount& rhv);

    void setPercentage(const double percentage);
    double getPercentage() const;
    double calculateInterest() const;

private:
    double percentage_;
};

#endif /// __SAVING_ACCOUNT_HPP__

