#include "headers/Rectangle.hpp"
#include <gtest/gtest.h>
#include <sstream>
#include <string>
#include <cctype>


TEST(RectangleTest, ParameterizedConstructor)
{
    Coordinate A(0, 9);
    Coordinate B(9, 0);
    Coordinate C(11, 2);
    Coordinate D(2, 11);

    Rectangle rectangle(A, B, C, D, '*', '*');

    EXPECT_EQ(rectangle.getPointA().getX(), 0);
    EXPECT_EQ(rectangle.getPointA().getY(), 9);

    EXPECT_EQ(rectangle.getPointB().getX(), 9);
    EXPECT_EQ(rectangle.getPointB().getY(), 0);

    EXPECT_EQ(rectangle.getPointC().getX(), 11);
    EXPECT_EQ(rectangle.getPointC().getY(), 2);

    EXPECT_EQ(rectangle.getPointD().getX(), 2);
    EXPECT_EQ(rectangle.getPointD().getY(), 11);

    EXPECT_EQ(rectangle.getFillCharacter(), '*');
    EXPECT_EQ(rectangle.getPerimeterCharacter(), '*');
}


TEST(RectangleTest, CopyConstructor)
{
    Coordinate A(1, 1);
    Coordinate B(5, 1);
    Coordinate C(5, 3);
    Coordinate D(1, 3);

    Rectangle r1(A, B, C, D, '#', '#');
    Rectangle r2(r1);

    EXPECT_EQ(r2.getPointA().getX(), 1);
    EXPECT_EQ(r2.getPointB().getY(), 1);
    EXPECT_EQ(r2.getFillCharacter(), '#');
}


TEST(RectangleTest, SetAndGetCharacters)
{
    Coordinate A(0, 0);
    Coordinate B(5, 0);
    Coordinate C(5, 4);
    Coordinate D(0, 4);

    Rectangle rectangle(A, B, C, D, '*', '#');

    rectangle.setFillCharacter('~');
    rectangle.setPerimeterCharacter('@');

    EXPECT_EQ(rectangle.getFillCharacter(), '~');
    EXPECT_EQ(rectangle.getPerimeterCharacter(), '@');
}


TEST(RectangleTest, AreaAndPerimeter)
{
    Coordinate A(0, 0);
    Coordinate B(4, 0);
    Coordinate C(4, 3);
    Coordinate D(0, 3);

    Rectangle rectangle(A, B, C, D, '*', '*');

    EXPECT_NEAR(rectangle.getArea(), 12.0, 1e-9);
    EXPECT_NEAR(rectangle.getPerimeter(), 14.0, 1e-9);
}


TEST(RectangleTest, WidthAndLength)
{
    Coordinate A(0, 0);
    Coordinate B(6, 0);
    Coordinate C(6, 2);
    Coordinate D(0, 2);

    Rectangle rectangle(A, B, C, D, '*', '*');

    EXPECT_NEAR(rectangle.getWidth(), 2.0, 1e-9);
    EXPECT_NEAR(rectangle.getLength(), 6.0, 1e-9);
}


TEST(RectangleTest, IsSquare)
{
    Coordinate A(0, 0);
    Coordinate B(3, 0);
    Coordinate C(3, 3);
    Coordinate D(0, 3);

    Rectangle square(A, B, C, D, '*', '*');

    EXPECT_TRUE(square.isSquare());
}


TEST(RectangleTest, NotSquare)
{
    Coordinate A(0, 0);
    Coordinate B(5, 0);
    Coordinate C(5, 3);
    Coordinate D(0, 3);

    Rectangle rect(A, B, C, D, '*', '*');

    EXPECT_FALSE(rect.isSquare());
}


std::string trimTrailingSpacesLines(const std::string& str)
{
    std::stringstream input(str);
    std::string line;
    std::string result;

    while (std::getline(input, line)) {

        while (!line.empty() && std::isspace(line[line.size() - 1])) {
            line.erase(line.size() - 1);
        }

        result += line + "\n";
    }

    return result;
}


TEST(RectangleTest, DrawTest)
{
    Coordinate A(0, 9);
    Coordinate B(9, 0);
    Coordinate C(11, 2);
    Coordinate D(2, 11);

    Rectangle rectangle(A, B, C, D, '*', '*');


    std::stringstream buffer;

    std::streambuf* old =
        std::cout.rdbuf(buffer.rdbuf());


    rectangle.draw();


    std::cout.rdbuf(old);


    EXPECT_FALSE(buffer.str().empty());
}


int
main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}

