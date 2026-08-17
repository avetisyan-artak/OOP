#include "headers/Account.hpp"
#include <cassert>

Account::Account(const double balance)
    : balance_(balance)
{
}

Account::Account(const Account& rhv)
    : balance_(rhv.balance_)
{
}

void
Account::setInitialBalance(const double balance)
{
    assert(balance >= 0);
    balance_ = balance;
}

double
Account::getBalance() const
{
    return balance_;
}

