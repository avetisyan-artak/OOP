#include <gtest/gtest.h>
#include "headers/Rectangle.hpp"
#include "headers/Square.hpp"
#include "headers/Triangle.hpp"
#include "headers/Shape.hpp"
#include <vector>

TEST(RectangleTest, AreaCalculation)
{
    Rectangle r(4, 5, '#');
    EXPECT_DOUBLE_EQ(r.getArea(), 20.0);
}

TEST(RectangleTest, FillCharacter)
{
    Rectangle r(2, 3, '@');
    EXPECT_EQ(r.getSymbol(), '@');
}

TEST(SquareTest, AreaCalculation)
{
    Square s(5, '*');
    EXPECT_DOUBLE_EQ(s.getArea(), 25.0);
}

TEST(SquareTest, FillCharacter)
{
    Square s(3, '+');
    EXPECT_EQ(s.getSymbol(), '+');
}

TEST(TriangleTest, AreaCalculation)
{
    Triangle t(3, 4, 5, '$');
    const double expectedArea = 6.0;
    EXPECT_NEAR(t.getArea(), expectedArea, 1e-6);
}

TEST(TriangleTest, FillCharacter)
{
    Triangle t(3, 4, 5, '#');
    EXPECT_EQ(t.getSymbol(), '#');
}

TEST(ShapeHierarchyTest, PolymorphicDraw)
{
    std::vector<Shape*> shapes;
    shapes.push_back(new Square(5, '#'));
    shapes.push_back(new Rectangle(4, 6, '$'));
    shapes.push_back(new Triangle(5, 6, 7, '@'));

    for (size_t i = 0; i < shapes.size(); ++i) {
        std::cout << "Shape " << i + 1 << " details:\n";
        shapes[i]->print();
        std::cout << std::endl;
        shapes[i]->draw();
        std::cout << std::endl << std::endl;
    }

    for (size_t i = 0; i < shapes.size(); ++i) {
        delete shapes[i];
    }
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

