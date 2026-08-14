#ifndef __ACCOUNT_HPP__
#define __ACCOUNT_HPP__

class Account
{
public:
    Account(const double initialBalance = 0.0);
    Account(const Account& rhv);

    void setInitialBalance(const double initialBalance);
    void credit(const double currentBalance);
    void debit(const double amount);
    double getBalance() const;

private:
    double balance_;
};

#endif /// __ACCOUNT_HPP__

