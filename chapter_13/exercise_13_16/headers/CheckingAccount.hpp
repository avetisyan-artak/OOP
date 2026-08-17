#ifndef __CHECKING_ACCOUNT_HPP__
#define __CHECKING_ACCOUNT_HPP__
#include "Account.hpp"

class CheckingAccount: public Account
{
public:
    CheckingAccount(const double balance = 0.0, const double fee = 0.0);
    CheckingAccount(const CheckingAccount& rhv);
    virtual ~CheckingAccount() {}

    void setFee(const double fee);
    double getFee() const;

    virtual void credit(const double amount);
    virtual void debit(const double amount);
    virtual void print() const;

private:
    double fee_;
};

#endif /// __CHECKING_ACCOUNT_HPP__

