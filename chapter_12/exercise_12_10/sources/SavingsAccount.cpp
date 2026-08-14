#include "headers/SavingsAccount.hpp"

SavingAccount::SavingAccount(const double initialBalance, const double percentage)
    : Account(initialBalance)
    , percentage_(percentage)
{
}

SavingAccount::SavingAccount(const SavingAccount& rhv)
    : Account(rhv)
    , percentage_(rhv.percentage_)
{
}

void
SavingAccount::setPercentage(const double percentage)
{
    percentage_ = percentage;
}

double
SavingAccount::getPercentage() const
{
    return percentage_;
}

double
SavingAccount::calculateInterest() const
{
    return getBalance() * percentage_;
}

