#include "headers/Time.hpp"
#include <gtest/gtest.h>


TEST(TimeTest, ConstructorAndGetters)
{
    Time t(14, 30, 45);

    EXPECT_EQ(t.getHour(), 14);
    EXPECT_EQ(t.getMinute(), 30);
    EXPECT_EQ(t.getSecond(), 45);
}


TEST(TimeTest, DefaultConstructor)
{
    Time t;

    EXPECT_GE(t.getHour(), 0);
    EXPECT_LT(t.getHour(), 24);

    EXPECT_GE(t.getMinute(), 0);
    EXPECT_LT(t.getMinute(), 60);

    EXPECT_GE(t.getSecond(), 0);
    EXPECT_LT(t.getSecond(), 60);
}


TEST(TimeTest, CopyConstructor)
{
    Time t1(10, 20, 30);

    Time t2(t1);

    EXPECT_EQ(t2.getHour(), 10);
    EXPECT_EQ(t2.getMinute(), 20);
    EXPECT_EQ(t2.getSecond(), 30);
}


TEST(TimeTest, Setters)
{
    Time t;

    EXPECT_TRUE(t.setHour(12));
    EXPECT_TRUE(t.setMinute(59));
    EXPECT_TRUE(t.setSecond(0));

    EXPECT_EQ(t.getHour(), 12);
    EXPECT_EQ(t.getMinute(), 59);
    EXPECT_EQ(t.getSecond(), 0);


    EXPECT_FALSE(t.setHour(25));
    EXPECT_FALSE(t.setMinute(61));
    EXPECT_FALSE(t.setSecond(61));
}


TEST(TimeTest, SetHourValidValues)
{
    Time t;

    EXPECT_TRUE(t.setHour(0));
    EXPECT_EQ(t.getHour(), 0);

    EXPECT_TRUE(t.setHour(23));
    EXPECT_EQ(t.getHour(), 23);
}


TEST(TimeTest, SetMinuteValidValues)
{
    Time t;

    EXPECT_TRUE(t.setMinute(0));
    EXPECT_EQ(t.getMinute(), 0);

    EXPECT_TRUE(t.setMinute(59));
    EXPECT_EQ(t.getMinute(), 59);
}


TEST(TimeTest, SetSecondValidValues)
{
    Time t;

    EXPECT_TRUE(t.setSecond(0));
    EXPECT_EQ(t.getSecond(), 0);

    EXPECT_TRUE(t.setSecond(59));
    EXPECT_EQ(t.getSecond(), 59);
}


TEST(TimeTest, InvalidValuesDoNotChangeData)
{
    Time t(10, 20, 30);

    EXPECT_FALSE(t.setHour(25));
    EXPECT_FALSE(t.setMinute(70));
    EXPECT_FALSE(t.setSecond(90));

    EXPECT_EQ(t.getHour(), 10);
    EXPECT_EQ(t.getMinute(), 20);
    EXPECT_EQ(t.getSecond(), 30);
}


TEST(TimeTest, MultipleSetOperations)
{
    Time t;

    t.setHour(8);
    t.setMinute(15);
    t.setSecond(20);

    EXPECT_EQ(t.getHour(), 8);
    EXPECT_EQ(t.getMinute(), 15);
    EXPECT_EQ(t.getSecond(), 20);


    t.setHour(18);
    t.setMinute(45);
    t.setSecond(59);

    EXPECT_EQ(t.getHour(), 18);
    EXPECT_EQ(t.getMinute(), 45);
    EXPECT_EQ(t.getSecond(), 59);
}


TEST(TimeTest, BoundaryValues)
{
    Time t;

    EXPECT_TRUE(t.setHour(0));
    EXPECT_TRUE(t.setMinute(0));
    EXPECT_TRUE(t.setSecond(0));


    EXPECT_TRUE(t.setHour(23));
    EXPECT_TRUE(t.setMinute(59));
    EXPECT_TRUE(t.setSecond(59));


    EXPECT_EQ(t.getHour(), 23);
    EXPECT_EQ(t.getMinute(), 59);
    EXPECT_EQ(t.getSecond(), 59);
}


TEST(TimeTest, TickFunction)
{
    Time t(23, 59, 59);

    t.tick();

    EXPECT_EQ(t.getHour(), 0);
    EXPECT_EQ(t.getMinute(), 0);
    EXPECT_EQ(t.getSecond(), 0);
}


TEST(TimeTest, TickOneSecond)
{
    Time t(12, 30, 45);

    t.tick();

    EXPECT_EQ(t.getHour(), 12);
    EXPECT_EQ(t.getMinute(), 30);
    EXPECT_EQ(t.getSecond(), 46);
}


TEST(TimeTest, TickSecondToMinute)
{
    Time t(12, 30, 59);

    t.tick();

    EXPECT_EQ(t.getHour(), 12);
    EXPECT_EQ(t.getMinute(), 31);
    EXPECT_EQ(t.getSecond(), 0);
}


TEST(TimeTest, TickMinuteToHour)
{
    Time t(12, 59, 59);

    t.tick();

    EXPECT_EQ(t.getHour(), 13);
    EXPECT_EQ(t.getMinute(), 0);
    EXPECT_EQ(t.getSecond(), 0);
}


TEST(TimeTest, TickSeveralSeconds)
{
    Time t(1, 1, 1);

    t.tick();
    t.tick();
    t.tick();

    EXPECT_EQ(t.getHour(), 1);
    EXPECT_EQ(t.getMinute(), 1);
    EXPECT_EQ(t.getSecond(), 4);
}


TEST(TimeTest, TickOneMinute)
{
    Time t(5, 10, 0);

    for (int i = 0; i < 60; ++i) {
        t.tick();
    }

    EXPECT_EQ(t.getHour(), 5);
    EXPECT_EQ(t.getMinute(), 11);
    EXPECT_EQ(t.getSecond(), 0);
}


TEST(TimeTest, TickOneHour)
{
    Time t(5, 0, 0);

    for (int i = 0; i < 3600; ++i) {
        t.tick();
    }

    EXPECT_EQ(t.getHour(), 6);
    EXPECT_EQ(t.getMinute(), 0);
    EXPECT_EQ(t.getSecond(), 0);
}


TEST(TimeTest, TickFullDay)
{
    Time t(0, 0, 0);

    for (int i = 0; i < 86400; ++i) {
        t.tick();
    }

    EXPECT_EQ(t.getHour(), 0);
    EXPECT_EQ(t.getMinute(), 0);
    EXPECT_EQ(t.getSecond(), 0);
}


int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

