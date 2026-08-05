#include "headers/SavingAccount.hpp"
#include <iostream>
#include <cassert>
#include <iomanip>

double SavingAccount::annualInterestRate_ = 0;

SavingAccount::SavingAccount(const double savingBalance)
{
    setSavingBalance(savingBalance);
}

SavingAccount::SavingAccount(const SavingAccount& rhv)
{
    setSavingBalance(rhv.getSavingBalance());
}

void
SavingAccount::setSavingBalance(const double balance)
{
    assert(balance > 0);
    savingBalance_ = balance;
}

double
SavingAccount::getSavingBalance() const
{
    return savingBalance_;
}

double
SavingAccount::getAnnualInterestRate()
{
    return annualInterestRate_;
}

void
SavingAccount::calculateMonthlyInterest()
{
    const double procent = (getSavingBalance() * getAnnualInterestRate()) / COUNT_OF_MONTH;
    setSavingBalance(procent + getSavingBalance());
}

void
SavingAccount::modifyInterestRate(const double annualRate)
{
    assert(annualRate >= 0);
    annualInterestRate_ = annualRate;
}

void
SavingAccount::printResult() const
{
    std::cout << std::fixed << std::setprecision(2) << savingBalance_ << std::endl;
}

