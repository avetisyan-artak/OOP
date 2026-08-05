#include <gtest/gtest.h>
#include "headers/Date.hpp"
#include <ctime>
#include <string>

TEST(DateTest, Constructor)
{
    Date d(2025, 5, 15);

    EXPECT_EQ(d.getYear(), 2025);
    EXPECT_EQ(d.getMonth(), 5);
    EXPECT_EQ(d.getDay(), 15);
}

TEST(DateTest, NextDayNormal)
{
    Date d(2022, 4, 20);

    d.nextDay();

    EXPECT_EQ(d.getYear(), 2022);
    EXPECT_EQ(d.getMonth(), 4);
    EXPECT_EQ(d.getDay(), 21);
}

TEST(DateTest, NextDayMonthChange)
{
    Date d(2022, 6, 30);

    d.nextDay();

    EXPECT_EQ(d.getDay(), 1);
    EXPECT_EQ(d.getMonth(), 7);
    EXPECT_EQ(d.getYear(), 2022);
}

TEST(DateTest, NextDayYearChange)
{
    Date d(2024, 12, 31);

    d.nextDay();

    EXPECT_EQ(d.getDay(), 1);
    EXPECT_EQ(d.getMonth(), 1);
    EXPECT_EQ(d.getYear(), 2025);
}

TEST(DateTest, LeapYear)
{
    Date d(2024, 2, 28);

    d.nextDay();

    EXPECT_EQ(d.getDay(), 29);
    EXPECT_EQ(d.getMonth(), 2);
    EXPECT_EQ(d.getYear(), 2024);

    d.nextDay();

    EXPECT_EQ(d.getDay(), 1);
    EXPECT_EQ(d.getMonth(), 3);
    EXPECT_EQ(d.getYear(), 2024);
}

TEST(DateTest, ConstructorFromDayOfYearNormal)
{
    Date d(100, 2023);

    EXPECT_EQ(d.getYear(), 2023);
    EXPECT_EQ(d.getMonth(), 4);
    EXPECT_EQ(d.getDay(), 10);
}

TEST(DateTest, ConstructorFromDayOfYearLeap)
{
    Date d(60, 2024);

    EXPECT_EQ(d.getYear(), 2024);
    EXPECT_EQ(d.getMonth(), 2);
    EXPECT_EQ(d.getDay(), 29);
}

TEST(DateTest, ConstructorFromMonthName)
{
    Date d("October", 5, 2021);

    EXPECT_EQ(d.getYear(), 2021);
    EXPECT_EQ(d.getMonth(), 10);
    EXPECT_EQ(d.getDay(), 5);
}

TEST(DateTest, GetDayOfYearNormal)
{
    Date d(2023, 11, 1);

    EXPECT_EQ(d.getDayOfYear(), 305);
}

TEST(DateTest, GetDayOfYearLeap)
{
    Date d(2024, 11, 1);

    EXPECT_EQ(d.getDayOfYear(), 306);
}

TEST(DateTest, PrintFormats)
{
    Date d(2000, 7, 20);

    testing::internal::CaptureStdout();

    d.printNumeric();

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("20/7/2000"), std::string::npos);


    testing::internal::CaptureStdout();

    d.printTextual();

    output = testing::internal::GetCapturedStdout();

    EXPECT_FALSE(output.empty());


    testing::internal::CaptureStdout();

    d.printLong();

    output = testing::internal::GetCapturedStdout();

    EXPECT_FALSE(output.empty());
}

TEST(DateTest, DefaultConstructorSetsToday)
{
    const time_t now = time(0);

    tm* ltm = localtime(&now);

    const int expectedYear = 1900 + ltm->tm_year;
    const int expectedMonth = 1 + ltm->tm_mon;
    const int expectedDay = ltm->tm_mday;

    Date d;

    EXPECT_EQ(d.getYear(), expectedYear);
    EXPECT_EQ(d.getMonth(), expectedMonth);
    EXPECT_EQ(d.getDay(), expectedDay);
}


TEST(DateDeathTest, InvalidMonthName)
{
    ASSERT_DEATH(
    {
        Date d("NotAMonth", 15, 2025);
    }, ".*");
}


TEST(DateTest, Formats)
{
    const char* date1 = "11/30/2022";

    ASSERT_TRUE(Date::isRightFormat(date1));

    Date d1(date1);

    EXPECT_EQ(d1.getDay(), 30);
    EXPECT_EQ(d1.getMonth(), 11);
    EXPECT_EQ(d1.getYear(), 2022);


    const char* date2 = "250 2022";

    ASSERT_TRUE(Date::isRightFormat(date2));

    Date d2(date2);

    EXPECT_EQ(d2.getDay(), 7);
    EXPECT_EQ(d2.getMonth(), 9);
    EXPECT_EQ(d2.getYear(), 2022);
}


int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

