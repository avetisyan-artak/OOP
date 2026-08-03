#include "headers/Date.hpp"
#include <gtest/gtest.h>

TEST(DateTest, TestForConstructor)
{
    Date date1;

    date1.setMonth(2);
    date1.setDay(4);
    date1.setYear(2004);

    EXPECT_EQ(date1.getMonth(), 2);
    EXPECT_EQ(date1.getDay(), 4);
    EXPECT_EQ(date1.getYear(), 2004);
}

TEST(DateTest, TestForCopyConstructor)
{
    Date date1(12, 13, 1999);
    Date date2(date1);

    EXPECT_EQ(date2.getMonth(), 12);
    EXPECT_EQ(date2.getDay(), 13);
    EXPECT_EQ(date2.getYear(), 1999);
}

TEST(DateTest, TestForGetterFunctions)
{
    Date date1(1, 1, 2000);

    date1.setMonth(3);
    date1.setDay(21);
    date1.setYear(2002);

    EXPECT_EQ(date1.getMonth(), 3);
    EXPECT_EQ(date1.getDay(), 21);
    EXPECT_EQ(date1.getYear(), 2002);
}

TEST(DateTest, TestForNextDay1)
{
    Date date1(1, 1, 2001);

    date1.nextDay();

    EXPECT_EQ(date1.getMonth(), 1);
    EXPECT_EQ(date1.getDay(), 2);
    EXPECT_EQ(date1.getYear(), 2001);
}

TEST(DateTest, TestForNextDay2)
{
    Date date1(1, 31, 2001);

    date1.nextDay();

    EXPECT_EQ(date1.getMonth(), 2);
    EXPECT_EQ(date1.getDay(), 1);
    EXPECT_EQ(date1.getYear(), 2001);
}

TEST(DateTest, TestForNextDay3)
{
    Date date1(12, 31, 2001);

    date1.nextDay();

    EXPECT_EQ(date1.getMonth(), 1);
    EXPECT_EQ(date1.getDay(), 1);
    EXPECT_EQ(date1.getYear(), 2002);
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

