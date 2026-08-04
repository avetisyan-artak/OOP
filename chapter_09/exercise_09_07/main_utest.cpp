#include "headers/Time.hpp"
#include <gtest/gtest.h>
#include <ctime>

TEST(TimeTest, DefaultConstructor)
{
    Time myTime;
    time_t now = std::time(0);
    tm* utcTime = std::gmtime(&now);

    int expectedHour = (utcTime->tm_hour + 4) % 24;
    int expectedMinute = utcTime->tm_min;
    int expectedSecond = utcTime->tm_sec;

    EXPECT_EQ(myTime.getHour(), expectedHour);
    EXPECT_EQ(myTime.getMinute(), expectedMinute);
    EXPECT_EQ(myTime.getSecond(), expectedSecond);
}

TEST(TimeTest, SetFunctions)
{
    Time time(1, 1, 1);

    time.setHour(10);
    time.setMinute(20);
    time.setSecond(30);

    EXPECT_EQ(time.getHour(), 10);
    EXPECT_EQ(time.getMinute(), 20);
    EXPECT_EQ(time.getSecond(), 30);
}

TEST(TimeTest, CopyConstructor)
{
    Time time1(1, 1, 1);

    time1.setHour(12);
    time1.setMinute(20);
    time1.setSecond(10);

    Time time2(time1);

    EXPECT_EQ(time2.getHour(), 12);
    EXPECT_EQ(time2.getMinute(), 20);
    EXPECT_EQ(time2.getSecond(), 10);
}

TEST(TimeTest, getFunctions)
{
    Time time(12, 13, 14);

    EXPECT_EQ(time.getHour(), 12);
    EXPECT_EQ(time.getMinute(), 13);
    EXPECT_EQ(time. getSecond(), 14);
}

TEST(TimeTest, tickFunctionTest1)
{
    Time time1(12, 23, 11);

    time1.tick();

    EXPECT_EQ(time1.getHour(), 12);
    EXPECT_EQ(time1.getMinute(), 23);
    EXPECT_EQ(time1.getSecond(), 12);
}

TEST(TimeTest, tickFunctionTest2)
{
    Time time1(22, 59, 59);

    time1.tick();

    EXPECT_EQ(time1.getHour(), 23);
    EXPECT_EQ(time1.getMinute(), 0);
    EXPECT_EQ(time1.getSecond(), 0);
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

