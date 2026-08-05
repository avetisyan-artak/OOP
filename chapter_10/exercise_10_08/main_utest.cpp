#include "headers/SavingAccount.hpp"
#include <gtest/gtest.h>
#include <cmath>

const double SAVING_BALANCE_FIRST = 2000.0;
const double SAVING_BALANCE_SECOND = 3000.0;
const double INTEREST_RATE_3 = 0.03;
const double INTEREST_RATE_4 = 0.04;
const double EPSILON = 1e-9;

bool doubleEquals(const double number1, const double number2, const double epsilon);

TEST(SavingAccountTest, InterestCalculation)
{
    SavingAccount saver1(SAVING_BALANCE_FIRST);
    SavingAccount saver2(SAVING_BALANCE_SECOND);

    SavingAccount::modifyInterestRate(INTEREST_RATE_3);
    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();

    double expected1_after3 = SAVING_BALANCE_FIRST + SAVING_BALANCE_FIRST * (INTEREST_RATE_3 / COUNT_OF_MONTH);
    double expected2_after3 = SAVING_BALANCE_SECOND + SAVING_BALANCE_SECOND * (INTEREST_RATE_3 / COUNT_OF_MONTH);

    ASSERT_TRUE(doubleEquals(saver1.getSavingBalance(), expected1_after3, EPSILON));
    ASSERT_TRUE(doubleEquals(saver2.getSavingBalance(), expected2_after3, EPSILON));

    SavingAccount::modifyInterestRate(INTEREST_RATE_4);
    saver1.calculateMonthlyInterest();
    saver2.calculateMonthlyInterest();

    const double expected1_after4 = expected1_after3 + expected1_after3 * (INTEREST_RATE_4 / COUNT_OF_MONTH);
    const double expected2_after4 = expected2_after3 + expected2_after3 * (INTEREST_RATE_4 / COUNT_OF_MONTH);

    ASSERT_TRUE(doubleEquals(saver1.getSavingBalance(), expected1_after4, EPSILON));
    ASSERT_TRUE(doubleEquals(saver2.getSavingBalance(), expected2_after4, EPSILON));
}


int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

bool
doubleEquals(const double number1, const double number2, const double epsilon)
{
    return std::fabs(number1 - number2) < epsilon;
}

