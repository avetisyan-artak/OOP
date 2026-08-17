#include "headers/SavingsAccount.hpp"
#include <cassert>
#include <iostream>

SavingsAccount::SavingsAccount(const double balance, const double percentage)
    : Account(balance)
    , percentage_(percentage)
{
}

SavingsAccount::SavingsAccount(const SavingsAccount& rhv)
    : Account(rhv)
    , percentage_(rhv.percentage_)
{
}

void
SavingsAccount::setPercentage(const double percentage)
{
    assert(percentage >= 0);
    percentage_ = percentage;
}

double
SavingsAccount::getPercentage() const
{
    return percentage_;
}

double
SavingsAccount::calculateInterest() const
{
    return getBalance() * (percentage_ / 100.0);
}

void
SavingsAccount::debit(const double amount)
{
    assert(amount >= 0 && amount <= getBalance());
    setInitialBalance(getBalance() - amount);
}

void
SavingsAccount::credit(const double amount)
{
    assert(amount >= 0);
    setInitialBalance(getBalance() + amount);
}

void
SavingsAccount::print() const
{
    std::cout << "Savings Account balance: " << getBalance()
              << "Interest rate: "           << percentage_ << "%\n";
}

