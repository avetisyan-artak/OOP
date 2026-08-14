#include "headers/Account.hpp"
#include <cassert>

Account::Account(const double initialBalance)
{
    assert(initialBalance >= 0);
    balance_ = initialBalance;
}

Account::Account(const Account& rhv)
    : balance_(rhv.balance_)
{
}

void
Account::setInitialBalance(const double initialBalance)
{
    assert(initialBalance >= 0);
    balance_ = initialBalance;
}

double
Account::getBalance() const
{
    return balance_;
}

void
Account::credit(const double amount)
{
    assert(amount >= 0);
    balance_ += amount;
}

void
Account::debit(const double amount)
{
    assert(amount >= 0 && amount <= balance_);
    balance_ -= amount;
}

