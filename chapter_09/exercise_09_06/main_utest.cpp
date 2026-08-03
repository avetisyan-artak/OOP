#include "headers/Rational.hpp"
#include "gtest/gtest.h"

TEST(Rational, sum1)
{
    Rational a(4, 8);
    Rational b(9, 2);
    Rational c = b.sumOfNumbers(a);
    EXPECT_EQ(c.getNumerator(), 5);
    EXPECT_EQ(c.getDenominator(), 1);
}

TEST(Rational, sum2)
{
    Rational a(1, 4);
    Rational b(1, 4);
    Rational c = b.sumOfNumbers(a);
    EXPECT_EQ(c.getNumerator(), 1);
    EXPECT_EQ(c.getDenominator(), 2);
}


TEST(Rational, subtract)
{
    Rational a(50, 8);
    Rational b(9, 2);
    Rational c = a.subOfNumbers(b);
    EXPECT_EQ(c.getNumerator(), 7);
    EXPECT_EQ(c.getDenominator(), 4);
}

TEST(Rational, multiply)
{
    Rational a(4, 8);
    Rational b(9, 2);
    Rational c = b.multiplicationOfNumbers(a);
    EXPECT_EQ(c.getNumerator(), 9);
    EXPECT_EQ(c.getDenominator(), 4);
}

TEST(Rational, divide)
{
    Rational a(4, 8);
    Rational b(9, 2);
    Rational c = a.dividingOfNumbers(b);
    EXPECT_EQ(c.getNumerator(), 1);
    EXPECT_EQ(c.getDenominator(), 9);
}

int
main(int argc, char **argv) 
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

