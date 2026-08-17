#include "headers/CheckingAccount.hpp"
#include <cassert>
#include <iostream>

CheckingAccount::CheckingAccount(const double balance, const double fee)
    : Account(balance)
    , fee_(fee)
{
}

CheckingAccount::CheckingAccount(const CheckingAccount& rhv)
    : Account(rhv)
    , fee_(rhv.fee_)
{
}

void
CheckingAccount::setFee(const double fee)
{
    assert(fee > 0);
    fee_ = fee;
}

double
CheckingAccount::getFee() const
{
    return fee_;
}

void
CheckingAccount::credit(const double amount)
{
    assert(amount >= 0);
    setInitialBalance(getBalance() + amount - fee_);
}

void
CheckingAccount::debit(const double amount)
{
    assert(amount >= 0 && amount + fee_ <= getBalance());
    setInitialBalance(getBalance() - amount - fee_);
}

void
CheckingAccount::print() const
{
    std::cout << "Checking Account balance: " << getBalance()
              << " (fee: " << fee_ << ")"     << std::endl;
}

