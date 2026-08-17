#ifndef __ACOUNT_HPP__
#define __ACOUNT_HPP__

class Account
{
public:
    Account(const double balance = 0.0);
    Account(const Account& rhv);
    virtual ~Account() {}

    void setInitialBalance(const double balance);
    double getBalance() const;

    virtual void credit(const double amount) = 0;
    virtual void debit(const double debit) = 0;
    virtual void print() const = 0;

private:
    double balance_;
};

#endif /// __ACOUNT_HPP__

