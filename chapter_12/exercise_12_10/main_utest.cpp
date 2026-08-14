#include <gtest/gtest.h>
#include "headers/Account.hpp"
#include "headers/SavingsAccount.hpp"
#include "headers/CheckingAccount.hpp"

TEST(AccountTest, DebitValidAmount)
{
    Account acc(100.0);
    acc.debit(40.0);
    EXPECT_DOUBLE_EQ(acc.getBalance(), 60.0);
}

TEST(AccountTest, DebitExactBalance)
{
    Account acc(100.0);
    acc.debit(100.0);
    EXPECT_DOUBLE_EQ(acc.getBalance(), 0.0);
}

TEST(AccountDeathTest, DebitNegativeAmount)
{
    Account acc(100.0);
    EXPECT_DEATH(acc.debit(-10.0), ".*");
}

TEST(AccountDeathTest, DebitMoreThanBalance)
{
    Account acc(100.0);
    EXPECT_DEATH(acc.debit(150.0), ".*");
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

