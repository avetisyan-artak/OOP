#include "headers/CheckingAccount.hpp"
#include <cassert>

CheckingAccount::CheckingAccount(const double initialBalance, const double fee)
    : Account(initialBalance)
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
    assert(amount >= 0 && fee_ <= Account::getBalance());
    Account::credit(amount);
    Account::debit(fee_);
}

void
CheckingAccount::debit(const double amount)
{
    Account::debit(amount);
    Account::debit(fee_);
}

