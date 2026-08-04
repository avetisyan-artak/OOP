#include "gtest/gtest.h"
#include "headers/Rectangle.hpp"


TEST(RectangleTest, DefaultConstructor)
{
    Point p0 = {0.0, 0.0};

    Rectangle rect;

    EXPECT_DOUBLE_EQ(rect.getPoint1().x, p0.x);
    EXPECT_DOUBLE_EQ(rect.getPoint1().y, p0.y);

    EXPECT_DOUBLE_EQ(rect.getPoint2().x, p0.x);
    EXPECT_DOUBLE_EQ(rect.getPoint2().y, p0.y);

    EXPECT_DOUBLE_EQ(rect.getPoint3().x, p0.x);
    EXPECT_DOUBLE_EQ(rect.getPoint3().y, p0.y);

    EXPECT_DOUBLE_EQ(rect.getPoint4().x, p0.x);
    EXPECT_DOUBLE_EQ(rect.getPoint4().y, p0.y);
}

TEST(RectangleTest, ConstructorTest)
{
    Point p1 = {0.0, 0.0};
    Point p2 = {4.0, 0.0};
    Point p3 = {4.0, 3.0};
    Point p4 = {0.0, 3.0};

    Rectangle rect(p1, p2, p3, p4);

    EXPECT_DOUBLE_EQ(rect.getPoint1().x, 0.0);
    EXPECT_DOUBLE_EQ(rect.getPoint1().y, 0.0);

    EXPECT_DOUBLE_EQ(rect.getPoint2().x, 4.0);
    EXPECT_DOUBLE_EQ(rect.getPoint2().y, 0.0);

    EXPECT_DOUBLE_EQ(rect.getPoint3().x, 4.0);
    EXPECT_DOUBLE_EQ(rect.getPoint3().y, 3.0);

    EXPECT_DOUBLE_EQ(rect.getPoint4().x, 0.0);
    EXPECT_DOUBLE_EQ(rect.getPoint4().y, 3.0);
}


TEST(RectangleTest, CopyConstructor)
{
    Point p1 = {0.0, 0.0};
    Point p2 = {4.0, 0.0};
    Point p3 = {4.0, 3.0};
    Point p4 = {0.0, 3.0};

    Rectangle rect1(p1, p2, p3, p4);
    Rectangle rect2(rect1);

    EXPECT_DOUBLE_EQ(rect2.getPoint1().x, p1.x);
    EXPECT_DOUBLE_EQ(rect2.getPoint1().y, p1.y);

    EXPECT_DOUBLE_EQ(rect2.getPoint2().x, p2.x);
    EXPECT_DOUBLE_EQ(rect2.getPoint2().y, p2.y);

    EXPECT_DOUBLE_EQ(rect2.getPoint3().x, p3.x);
    EXPECT_DOUBLE_EQ(rect2.getPoint3().y, p3.y);

    EXPECT_DOUBLE_EQ(rect2.getPoint4().x, p4.x);
    EXPECT_DOUBLE_EQ(rect2.getPoint4().y, p4.y);
}

TEST(RectangleTest, AreaAndPerimeterTest)
{
    Point p1 = {0.0, 0.0};
    Point p2 = {4.0, 0.0};
    Point p3 = {4.0, 3.0};
    Point p4 = {0.0, 3.0};

    Rectangle rect(p1, p2, p3, p4);

    EXPECT_DOUBLE_EQ(rect.getArea(), 12.0);
    EXPECT_DOUBLE_EQ(rect.getPerimeter(), 14.0);
}

TEST(RectangleTest, SquareTest)
{
    Point p1 = {0.0, 0.0};
    Point p2 = {2.0, 0.0};
    Point p3 = {2.0, 2.0};
    Point p4 = {0.0, 2.0};

    Rectangle rect(p1, p2, p3, p4);

    EXPECT_DOUBLE_EQ(rect.getArea(), 4.0);
    EXPECT_DOUBLE_EQ(rect.getPerimeter(), 8.0);
    EXPECT_TRUE(rect.isSquare());
}

TEST(RectangleTest, NotSquareTest)
{
    Point p1 = {0.0, 0.0};
    Point p2 = {5.0, 0.0};
    Point p3 = {5.0, 2.0};
    Point p4 = {0.0, 2.0};

    Rectangle rect(p1, p2, p3, p4);

    EXPECT_FALSE(rect.isSquare());
}

TEST(RectangleTest, PrintCoordinatesTest)
{
    Point p1 = {0.0, 0.0};
    Point p2 = {1.0, 0.0};
    Point p3 = {1.0, 1.0};
    Point p4 = {0.0, 1.0};

    Rectangle rect(p1, p2, p3, p4);

    rect.printCordinates();
}

int
main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

