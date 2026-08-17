#include "headers/Account.hpp"
#include "headers/SavingsAccount.hpp"
#include "headers/CheckingAccount.hpp"
#include <gtest/gtest.h>
#include <vector>

TEST(SavingsAccountTest, CreditDebitInterest)
{
    SavingsAccount sa(1000.0, 5.0);

    sa.credit(200.0);
    EXPECT_DOUBLE_EQ(sa.getBalance(), 1200.0);

    sa.debit(100.0);
    EXPECT_DOUBLE_EQ(sa.getBalance(), 1100.0);

    double interest = sa.calculateInterest();
    EXPECT_DOUBLE_EQ(interest, 55.0);

    sa.credit(interest);
    EXPECT_DOUBLE_EQ(sa.getBalance(), 1155.0);
}

TEST(CheckingAccountTest, CreditDebitFee)
{
    CheckingAccount ca(500.0, 2.0);

    ca.credit(100.0);
    EXPECT_DOUBLE_EQ(ca.getBalance(), 598.0);

    ca.debit(50.0);
    EXPECT_DOUBLE_EQ(ca.getBalance(), 546.0);
}

TEST(PolymorphicBankingTest, MultipleAccounts)
{
    std::vector<Account*> accounts;

    SavingsAccount* sa1 = new SavingsAccount(1000.0, 5.0);
    CheckingAccount* ca1 = new CheckingAccount(500.0, 2.0);
    accounts.push_back(sa1);
    accounts.push_back(ca1);

    for (size_t i = 0; i < accounts.size(); ++i) {
        accounts[i]->credit(100.0);
        accounts[i]->debit(50.0);
    }

    sa1->credit(sa1->calculateInterest());

    EXPECT_DOUBLE_EQ(sa1->getBalance(), 1102.5);
    EXPECT_DOUBLE_EQ(ca1->getBalance(), 546.0);

    for (size_t i = 0; i < accounts.size(); ++i) {
        delete accounts[i];
    }
}

int
main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

