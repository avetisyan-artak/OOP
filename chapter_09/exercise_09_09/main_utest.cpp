#include "headers/DateAndTime.hpp"
#include <gtest/gtest.h>


TEST(DateAndTimeTest, DefaultConstructor)
{
    DateAndTime dateTime;

    EXPECT_GE(dateTime.getYear(), MIN_YEAR);
    EXPECT_LE(dateTime.getYear(), MAX_YEAR);

    EXPECT_GE(dateTime.getMonth(), 1);
    EXPECT_LE(dateTime.getMonth(), MONTH_COUNT);

    EXPECT_GE(dateTime.getDay(), 1);
    EXPECT_LE(dateTime.getDay(), MAX_DAY);

    EXPECT_GE(dateTime.getHours(), 0);
    EXPECT_LT(dateTime.getHours(), MAX_HOUR);

    EXPECT_GE(dateTime.getMinutes(), 0);
    EXPECT_LT(dateTime.getMinutes(), MAX_MINUTES);

    EXPECT_GE(dateTime.getSeconds(), 0);
    EXPECT_LT(dateTime.getSeconds(), MAX_SECONDS);
}

TEST(DateAndTimeTest, ParameterizedConstructor)
{
    DateAndTime dateTime(2025, 8, 4, 12, 30, 45);

    EXPECT_EQ(dateTime.getYear(), 2025);
    EXPECT_EQ(dateTime.getMonth(), 8);
    EXPECT_EQ(dateTime.getDay(), 4);

    EXPECT_EQ(dateTime.getHours(), 12);
    EXPECT_EQ(dateTime.getMinutes(), 30);
    EXPECT_EQ(dateTime.getSeconds(), 45);
}


TEST(DateAndTimeTest, CopyConstructor)
{
    DateAndTime date1(2025, 8, 4, 12, 30, 45);
    DateAndTime date2(date1);

    EXPECT_EQ(date2.getYear(), date1.getYear());
    EXPECT_EQ(date2.getMonth(), date1.getMonth());
    EXPECT_EQ(date2.getDay(), date1.getDay());

    EXPECT_EQ(date2.getHours(), date1.getHours());
    EXPECT_EQ(date2.getMinutes(), date1.getMinutes());
    EXPECT_EQ(date2.getSeconds(), date1.getSeconds());
}

TEST(DateAndTimeTest, SettersAndGetters)
{
    DateAndTime dateTime(2025, 1, 1, 0, 0, 0);

    dateTime.setYear(2030);
    dateTime.setMonth(5);
    dateTime.setDay(15);

    dateTime.setHours(23);
    dateTime.setMinutes(59);
    dateTime.setSeconds(58);

    EXPECT_EQ(dateTime.getYear(), 2030);
    EXPECT_EQ(dateTime.getMonth(), 5);
    EXPECT_EQ(dateTime.getDay(), 15);

    EXPECT_EQ(dateTime.getHours(), 23);
    EXPECT_EQ(dateTime.getMinutes(), 59);
    EXPECT_EQ(dateTime.getSeconds(), 58);
}


TEST(DateAndTimeTest, TickOneSecond)
{
    DateAndTime dateTime(2025, 8, 4, 10, 20, 30);

    dateTime.tick();

    EXPECT_EQ(dateTime.getSeconds(), 31);
}

TEST(DateAndTimeTest, TickToNextMinute)
{
    DateAndTime dateTime(2025, 8, 4, 10, 20, 59);

    dateTime.tick();

    EXPECT_EQ(dateTime.getHours(), 10);
    EXPECT_EQ(dateTime.getMinutes(), 21);
    EXPECT_EQ(dateTime.getSeconds(), 0);
}

TEST(DateAndTimeTest, TickToNextHour)
{
    DateAndTime dateTime(2025, 8, 4, 10, 59, 59);

    dateTime.tick();

    EXPECT_EQ(dateTime.getHours(), 11);
    EXPECT_EQ(dateTime.getMinutes(), 0);
    EXPECT_EQ(dateTime.getSeconds(), 0);
}

TEST(DateAndTimeTest, TickToNextDay)
{
    DateAndTime dateTime(2025, 8, 4, 23, 59, 59);

    dateTime.tick();

    EXPECT_EQ(dateTime.getDay(), 5);
    EXPECT_EQ(dateTime.getHours(), 0);
    EXPECT_EQ(dateTime.getMinutes(), 0);
    EXPECT_EQ(dateTime.getSeconds(), 0);
}

TEST(DateAndTimeTest, TickToNextMonth)
{
    DateAndTime dateTime(2025, 1, 31, 23, 59, 59);

    dateTime.tick();

    EXPECT_EQ(dateTime.getMonth(), 2);
    EXPECT_EQ(dateTime.getDay(), 1);
}

TEST(DateAndTimeTest, TickToNextYear)
{
    DateAndTime dateTime(2025, 12, 31, 23, 59, 59);

    dateTime.tick();

    EXPECT_EQ(dateTime.getYear(), 2026);
    EXPECT_EQ(dateTime.getMonth(), 1);
    EXPECT_EQ(dateTime.getDay(), 1);
}

TEST(DateAndTimeTest, NextDayNormal)
{
    DateAndTime dateTime(2025, 8, 10, 12, 0, 0);

    dateTime.nextDay();

    EXPECT_EQ(dateTime.getDay(), 11);
    EXPECT_EQ(dateTime.getMonth(), 8);
    EXPECT_EQ(dateTime.getYear(), 2025);
}

TEST(DateAndTimeTest, NextDayJanuaryToFebruary)
{
    DateAndTime dateTime(2025, 1, 31, 12, 0, 0);

    dateTime.nextDay();

    EXPECT_EQ(dateTime.getDay(), 1);
    EXPECT_EQ(dateTime.getMonth(), 2);
}

TEST(DateAndTimeTest, NextDayFebruaryNonLeapYear)
{
    DateAndTime dateTime(2025, 2, 28, 12, 0, 0);

    dateTime.nextDay();

    EXPECT_EQ(dateTime.getDay(), 1);
    EXPECT_EQ(dateTime.getMonth(), 3);
}


TEST(DateAndTimeTest, NextDayFebruaryLeapYear)
{
    DateAndTime dateTime(2024, 2, 28, 12, 0, 0);

    dateTime.nextDay();

    EXPECT_EQ(dateTime.getDay(), 29);
    EXPECT_EQ(dateTime.getMonth(), 2);
}

TEST(DateAndTimeTest, NextDayLeapYearEndFebruary)
{
    DateAndTime dateTime(2024, 2, 29, 12, 0, 0);

    dateTime.nextDay();

    EXPECT_EQ(dateTime.getDay(), 1);
    EXPECT_EQ(dateTime.getMonth(), 3);
}

TEST(DateAndTimeTest, NextDayApril30)
{
    DateAndTime dateTime(2025, 4, 30, 12, 0, 0);

    dateTime.nextDay();

    EXPECT_EQ(dateTime.getDay(), 1);
    EXPECT_EQ(dateTime.getMonth(), 5);
}

TEST(DateAndTimeTest, NextDayJune30)
{
    DateAndTime dateTime(2025, 6, 30, 12, 0, 0);

    dateTime.nextDay();

    EXPECT_EQ(dateTime.getDay(), 1);
    EXPECT_EQ(dateTime.getMonth(), 7);
}

TEST(DateAndTimeTest, NextYearFromDecember)
{
    DateAndTime dateTime(2025, 12, 31, 12, 0, 0);

    dateTime.nextDay();

    EXPECT_EQ(dateTime.getYear(), 2026);
    EXPECT_EQ(dateTime.getMonth(), 1);
    EXPECT_EQ(dateTime.getDay(), 1);
}

TEST(DateAndTimeTest, FullDayTick)
{
    DateAndTime dateTime(2025, 8, 4, 0, 0, 0);

    for (int i = 0; i < 86400; ++i) {
        dateTime.tick();
    }

    EXPECT_EQ(dateTime.getDay(), 5);
    EXPECT_EQ(dateTime.getHours(), 0);
    EXPECT_EQ(dateTime.getMinutes(), 0);
    EXPECT_EQ(dateTime.getSeconds(), 0);
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

