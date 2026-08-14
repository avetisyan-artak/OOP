#ifndef __CHECKING_ACCOUNT_HPP__
#define __CHECKING_ACCOUNT_HPP__
#include "Account.hpp"

class CheckingAccount: public Account
{
public:
    CheckingAccount(double initialBalance = 0.0, double fee = 0.0);
    CheckingAccount(const CheckingAccount& rhv);

    void credit(const double amount);
    void setFee(const double fee);
    void debit(const double amount);
    double getFee() const;

private:
    double fee_;
};

#endif /// __CHECKING_ACCOUNT_HPP__

