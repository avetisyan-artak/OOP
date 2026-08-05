#ifndef __SAVING_ACCOUNT_HPP__
#define __SAVING_ACCOUNT_HPP__

const int COUNT_OF_MONTH = 12;

class SavingAccount
{
public:
    static void modifyInterestRate(const double annualRate);
    static double getAnnualInterestRate();

private:
    static double annualInterestRate_;

public:
    SavingAccount(const double savingBalance);
    SavingAccount(const SavingAccount& rhv);

    void setSavingBalance(const double balance);
    double getSavingBalance() const;
    void calculateMonthlyInterest();
    void printResult() const;

private:
    double savingBalance_;
};

#endif /// __SAVING_ACCOUNT_HPP__

