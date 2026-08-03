#include "gtest/gtest.h"
#include "headers/HugeInteger.hpp"
#include <string>

HugeInteger fromString(const std::string& number)
{
    return HugeInteger(number.c_str());
}


TEST(HugeIntegerConstructorTest, DefaultConstructorProducesZero)
{
    HugeInteger hi;

    EXPECT_TRUE(hi.isZero());
}


TEST(HugeIntegerConstructorTest, IntegerConstructorWorks)
{
    HugeInteger hi(12345);
    HugeInteger expected = fromString("12345");

    EXPECT_TRUE(hi.isEqualTo(expected));
}


TEST(HugeIntegerConstructorTest, StringConstructorWorks)
{
    HugeInteger hi("9876543210");
    HugeInteger expected = fromString("9876543210");

    EXPECT_TRUE(hi.isEqualTo(expected));
}


TEST(HugeIntegerAddTest, SimpleAddition)
{
    HugeInteger a("123");
    HugeInteger b("456");

    HugeInteger result = a.add(b);

    EXPECT_TRUE(result.isEqualTo(fromString("579")));
}


TEST(HugeIntegerAddTest, CarryOverAddition)
{
    HugeInteger a("999");
    HugeInteger b("1");

    HugeInteger result = a.add(b);

    EXPECT_TRUE(result.isEqualTo(fromString("1000")));
}


TEST(HugeIntegerSubtractTest, SimpleSubtraction)
{
    HugeInteger a("500");
    HugeInteger b("123");

    HugeInteger result = a.substract(b);

    EXPECT_TRUE(result.isEqualTo(fromString("377")));
}


TEST(HugeIntegerSubtractTest, BorrowingSubtraction)
{
    HugeInteger a("1000");
    HugeInteger b("1");

    HugeInteger result = a.substract(b);

    EXPECT_TRUE(result.isEqualTo(fromString("999")));
}


TEST(HugeIntegerMultiplyTest, SimpleMultiplication)
{
    HugeInteger a("123");
    HugeInteger b("4");

    HugeInteger result = a.multiply(b);

    EXPECT_TRUE(result.isEqualTo(fromString("492")));
}


TEST(HugeIntegerMultiplyTest, LargeMultiplication)
{
    HugeInteger a("123456789");
    HugeInteger b("987654321");

    HugeInteger result = a.multiply(b);

    EXPECT_TRUE(result.isEqualTo(
        fromString("121932631112635269")
    ));
}


TEST(HugeIntegerComparisonTest, Equality)
{
    HugeInteger a("123456");
    HugeInteger b("123456");

    EXPECT_TRUE(a.isEqualTo(b));
    EXPECT_FALSE(a.isNotEqualTo(b));
}


TEST(HugeIntegerComparisonTest, Inequality)
{
    HugeInteger a("123456");
    HugeInteger b("654321");

    EXPECT_FALSE(a.isEqualTo(b));
    EXPECT_TRUE(a.isNotEqualTo(b));
}


TEST(HugeIntegerComparisonTest, LessThan)
{
    HugeInteger a("123");
    HugeInteger b("456");

    EXPECT_TRUE(a.isLessThan(b));
    EXPECT_FALSE(b.isLessThan(a));
}


TEST(HugeIntegerComparisonTest, GreaterThan)
{
    HugeInteger a("789");
    HugeInteger b("123");

    EXPECT_TRUE(a.isGreaterThan(b));
    EXPECT_FALSE(b.isGreaterThan(a));
}


TEST(HugeIntegerComparisonTest, LessThanOrEqual)
{
    HugeInteger a("123");
    HugeInteger b("123");
    HugeInteger c("456");

    EXPECT_TRUE(a.isLessThanOrEqualTo(b));
    EXPECT_TRUE(a.isLessThanOrEqualTo(c));
    EXPECT_FALSE(c.isLessThanOrEqualTo(a));
}


TEST(HugeIntegerComparisonTest, GreaterThanOrEqual)
{
    HugeInteger a("456");
    HugeInteger b("123");
    HugeInteger c("456");

    EXPECT_TRUE(a.isGreaterThanOrEqualTo(b));
    EXPECT_TRUE(a.isGreaterThanOrEqualTo(c));
    EXPECT_FALSE(b.isGreaterThanOrEqualTo(a));
}


TEST(HugeIntegerZeroTest, ZeroComparison)
{
    HugeInteger a;
    HugeInteger b("0");

    EXPECT_TRUE(a.isZero());
    EXPECT_TRUE(a.isEqualTo(b));
}


TEST(HugeIntegerCopyTest, CopyConstructor)
{
    HugeInteger a("123456789");

    HugeInteger b(a);

    EXPECT_TRUE(a.isEqualTo(b));
}


TEST(HugeIntegerAddTest, AdditionWithZero)
{
    HugeInteger a("12345");
    HugeInteger zero("0");

    HugeInteger result = a.add(zero);

    EXPECT_TRUE(result.isEqualTo(a));
}


TEST(HugeIntegerMultiplyTest, MultiplyByZero)
{
    HugeInteger a("12345");
    HugeInteger zero("0");

    HugeInteger result = a.multiply(zero);

    EXPECT_TRUE(result.isZero());
}


int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

