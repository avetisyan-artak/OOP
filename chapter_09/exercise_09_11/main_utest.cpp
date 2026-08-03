#include "headers/Rectangle.hpp"
#include <gtest/gtest.h>

TEST(RectangleTest, ConstructorTest)
{
    Rectangle rectangle1(2.0, 3.0);

    EXPECT_DOUBLE_EQ(rectangle1.getLength(), 2.0);
    EXPECT_DOUBLE_EQ(rectangle1.getWidth(), 3.0);
}

TEST(RectangleTest, CopyConstructorTest)
{
    Rectangle rectangle1(4.0, 2.3);
    Rectangle rectangle2(rectangle1);

    EXPECT_DOUBLE_EQ(rectangle2.getLength(), 4.0);
    EXPECT_DOUBLE_EQ(rectangle2.getWidth(), 2.3);
}

TEST(RectangleTest, TestForSetterAndGetter)
{
    Rectangle rectangle1(1.0, 1.0);

    rectangle1.setLength(3.4);
    rectangle1.setWidth(5.4);

    EXPECT_DOUBLE_EQ(rectangle1.getLength(), 3.4);
    EXPECT_DOUBLE_EQ(rectangle1.getWidth(), 5.4);
}

TEST(RectangleTest, PerimeterTest)
{
    Rectangle rectangle1(1.0, 1.0);

    rectangle1.setLength(3.4);
    rectangle1.setWidth(4.5);

    EXPECT_DOUBLE_EQ(rectangle1.getPerimeter(), 15.8);
}

TEST(RectangleTest, AreaTest)
{
    Rectangle rectangle1(1.0, 1.0);

    rectangle1.setLength(3.0);
    rectangle1.setWidth(3.0);

    EXPECT_DOUBLE_EQ(rectangle1.getArea(), 9.0);
}

TEST(RectangleTest, InvalidValuesTest)
{
    Rectangle rectangle1;

    EXPECT_FALSE(rectangle1.setLength(0));
    EXPECT_FALSE(rectangle1.setWidth(20));

    EXPECT_DOUBLE_EQ(rectangle1.getLength(), 1.0);
    EXPECT_DOUBLE_EQ(rectangle1.getWidth(), 1.0);
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

