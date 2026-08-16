#include "headers/Circle.hpp"
#include "headers/Square.hpp"
#include "headers/Triangle.hpp"
#include "headers/Cube.hpp"
#include "headers/Sphere.hpp"
#include "headers/Tetrahedron.hpp"
#include <gtest/gtest.h>
#include <cmath>
#include <vector>

const double EPS = 1e-6;

TEST(CircleTest, AreaAndRadius)
{
    Circle c(2.0);
    EXPECT_NEAR(c.getArea(), M_PI * 4.0, EPS);
    EXPECT_DOUBLE_EQ(c.getRadius(), 2.0);

    c.setRadius(3.0);
    EXPECT_NEAR(c.getArea(), M_PI * 9.0, EPS);
}

TEST(SquareTest, AreaAndSide)
{
    Square s(5.0);
    EXPECT_DOUBLE_EQ(s.getSide(), 5.0);
    EXPECT_DOUBLE_EQ(s.getArea(), 25.0);

    s.setSide(2.0);
    EXPECT_DOUBLE_EQ(s.getArea(), 4.0);
}

TEST(TriangleTest, ValidTriangleArea)
{
    Triangle t(3.0, 4.0, 5.0);
    double expectedArea = 6.0;
    EXPECT_NEAR(t.getArea(), expectedArea, EPS);
}

TEST(CubeTest, AreaAndVolume)
{
    Cube cube(2.0);
    EXPECT_DOUBLE_EQ(cube.getSide(), 2.0);
    EXPECT_DOUBLE_EQ(cube.getArea(), 24.0);
    EXPECT_DOUBLE_EQ(cube.getVolume(), 8.0);

    cube.setSide(3.0);
    EXPECT_DOUBLE_EQ(cube.getArea(), 54.0);
    EXPECT_DOUBLE_EQ(cube.getVolume(), 27.0);
}

TEST(SphereTest, AreaAndVolume)
{
    Sphere s(2.0);
    EXPECT_NEAR(s.getArea(), 16.0 * M_PI, EPS);
    EXPECT_NEAR(s.getVolume(), (4.0/3.0) * M_PI * std::pow(2.0, 3), EPS);
    s.setRadius(1.0);
    EXPECT_NEAR(s.getArea(), 4.0 * M_PI, EPS);
    EXPECT_NEAR(s.getVolume(), 4.0/3.0 * M_PI, EPS);
}

TEST(TetrahedronTest, AreaAndVolume)
{
    Tetrahedron t(2.0);
    double expectedArea = std::sqrt(3) * 4.0;
    double expectedVolume = 8.0 / (6.0 * std::sqrt(2.0));
    EXPECT_NEAR(t.getArea(), expectedArea, EPS);
    EXPECT_NEAR(t.getVolume(), expectedVolume, EPS);
}

TEST(ShapeHierarchyTest, PolymorphicCalls)
{
    std::vector<Shape*> shapes;
    shapes.push_back(new Circle(1.0));
    shapes.push_back(new Square(2.0));
    shapes.push_back(new Triangle(3.0, 4.0, 5.0));
    shapes.push_back(new Cube(1.0));
    shapes.push_back(new Sphere(1.0));
    shapes.push_back(new Tetrahedron(1.0));

    for (size_t i = 0; i < shapes.size(); ++i) {
        Shape* shape = shapes[i];
        shape->print();

        TwoDimensionalShape* twoD = dynamic_cast<TwoDimensionalShape*>(shape);
        ThreeDimensionalShape* threeD = dynamic_cast<ThreeDimensionalShape*>(shape);

        if (twoD) {
            double area = twoD->getArea();
            EXPECT_GT(area, 0.0);
        } else if (threeD) {
            double area = threeD->getArea();
            double volume = threeD->getVolume();
            EXPECT_GT(area, 0.0);
            EXPECT_GT(volume, 0.0);
        }
    }

    for (size_t i = 0; i < shapes.size(); ++i) {
        delete shapes[i];
    }
}

int
main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

