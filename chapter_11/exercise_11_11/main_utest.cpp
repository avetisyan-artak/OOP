#include "headers/DoubleSubscriptedArray.hpp"
#include <gtest/gtest.h>

TEST(DoubleSubscriptedArrayTest, ConstructorTest)
{
    DoubleSubscriptedArray arr(3, 4);
    EXPECT_EQ(arr.getRow(), 3);
    EXPECT_EQ(arr.getColumn(), 4);
    EXPECT_EQ(arr.getSize(), 12);

    for (int i = 0; i < arr.getRow(); ++i)
        for (int j = 0; j < arr.getColumn(); ++j)
            EXPECT_EQ(arr(i, j), 0);
}

TEST(DoubleSubscriptedArrayTest, SetAndGetTest)
{
    DoubleSubscriptedArray arr(2, 2);
    arr(0, 0) = 5;
    arr(1, 1) = 9;
    EXPECT_EQ(arr(0, 0), 5);
    EXPECT_EQ(arr(1, 1), 9);
}

TEST(DoubleSubscriptedArrayTest, operatorA)
{
    DoubleSubscriptedArray arr(2, 3), arr1(3, 2);
    EXPECT_FALSE( arr == arr1);
}

TEST(DoubleSubscriptedArrayTest, CopyConstructorTest)
{
    DoubleSubscriptedArray a(2, 3);
    a(0, 0) = 1;
    a(1, 2) = 7;

    DoubleSubscriptedArray b(a);
    EXPECT_EQ(b.getRow(), 2);
    EXPECT_EQ(b.getColumn(), 3);
    EXPECT_EQ(b(0, 0), 1);
    EXPECT_EQ(b(1, 2), 7);

    a(1, 2) = 99;  
    EXPECT_EQ(b(1, 2), 7);
}

TEST(DoubleSubscriptedArrayTest, EqualityOperatorsTest)
{
    DoubleSubscriptedArray a(2, 2);
    DoubleSubscriptedArray b(2, 2);
    DoubleSubscriptedArray c(3, 3);

    a(0, 0) = 1;
    b(0, 0) = 1;

    EXPECT_TRUE(a == b);
    EXPECT_FALSE(a != b);
    EXPECT_TRUE(a != c);
}

TEST(DoubleSubscriptedArrayTest, AssignmentTest
        ) {
    DoubleSubscriptedArray a(2, 2);
    a(0, 1) = 8;

    DoubleSubscriptedArray b(2, 2);
    b = a;

    EXPECT_EQ(b(0, 1), 8);
    EXPECT_TRUE(b == a);
}

TEST(DoubleSubscriptedArrayTest, OutputStreamTest)
{
    DoubleSubscriptedArray arr(2, 3);
    for (int i = 0; i < arr.getRow(); ++i)
        for (int j = 0; j < arr.getColumn(); ++j)
            arr(i, j) = i * 10 + j;

    std::ostringstream out;
    out << arr;
    std::string expected = "    0    1    2\n"
                           "   10   11   12\n";
    EXPECT_EQ(out.str(), expected);
}

TEST(DoubleSubscriptedArrayTest, OperatorParentheses) 
{
    DoubleSubscriptedArray arr(3, 4); 

    for (int i = 0; i < arr.getRow(); ++i) {
        for (int j = 0; j < arr.getColumn(); ++j) {
            arr(i, j) = i * 10 + j;
        }
    }

    for (int i = 0; i < arr.getRow(); ++i) {
        for (int j = 0; j < arr.getColumn(); ++j) {
            EXPECT_EQ(arr(i, j), i * 10 + j);
        }
    }

    const DoubleSubscriptedArray& constArr = arr;
    for (int i = 0; i < constArr.getRow(); ++i) {
        for (int j = 0; j < constArr.getColumn(); ++j) {
            EXPECT_EQ(constArr(i, j), i * 10 + j);
        }
    }
}

TEST(DoubleSubscriptedArrayTest, SortDescending)
{
    DoubleSubscriptedArray arr(2, 3);
    arr(0, 0) = 5;
    arr(0, 1) = 1;
    arr(0, 2) = 7;
    arr(1, 0) = 3;
    arr(1, 1) = 9;
    arr(1, 2) = 2;

    arr.sort();

    EXPECT_EQ(arr(0, 0), 9);
    EXPECT_EQ(arr(0, 1), 7);
    EXPECT_EQ(arr(0, 2), 5);
    EXPECT_EQ(arr(1, 0), 3);
    EXPECT_EQ(arr(1, 1), 2);
    EXPECT_EQ(arr(1, 2), 1);
}

TEST(DoubleSubscriptedArrayTest, SortWithDuplicates)
{
    DoubleSubscriptedArray arr(2, 2);
    arr(0, 0) = 4;
    arr(0, 1) = 4;
    arr(1, 0) = 1;
    arr(1, 1) = 1;

    arr.sort();

    EXPECT_EQ(arr(0, 0), 4);
    EXPECT_EQ(arr(0, 1), 4);
    EXPECT_EQ(arr(1, 0), 1);
    EXPECT_EQ(arr(1, 1), 1);
}

TEST(DoubleSubscriptedArrayTest, SortEmptyArray) 
{
    DoubleSubscriptedArray arr(0, 0);
    EXPECT_NO_THROW(arr.sort());
}

TEST(DoubleSubscriptedArrayTest, SortSingleElement) 
{
    DoubleSubscriptedArray arr(1, 1);
    arr(0, 0) = 42;
    arr.sort();
    EXPECT_EQ(arr(0, 0), 42);
}


TEST(DoubleSubscriptedArrayTest, ModifyElementTriggersSort)
{
    DoubleSubscriptedArray array(2, 2);
    std::istringstream in("1 2 3 4");
    in >> array;
    array(1, 1) = 10;
    EXPECT_EQ(array(0, 0), 1);
}

TEST(DoubleSubscriptedArrayTest, MaxElementTracking)
{
    DoubleSubscriptedArray array(2, 2);
    std::istringstream in("1 2 3 4");
    in >> array;
    EXPECT_EQ(array(1,1), 4);
}

TEST(DoubleSubscriptedArrayTest, ChangeGreatestAndCheckAgain)
{
    DoubleSubscriptedArray array(2, 2);
    std::istringstream in("1 2 3 4");
    in >> array;

    EXPECT_EQ(array(1,1 ), 4);
    array(0, 1) = 99;
    EXPECT_EQ(array(0, 1), 99);
}

TEST(DoubleSubscriptedArrayTest, ManualInputAndSortWithPrint)
{
    DoubleSubscriptedArray arr(2, 3);

    arr(0, 0) = 5;
    arr(0, 1) = 1;
    arr(0, 2) = 9;
    arr(1, 0) = 3;
    arr(1, 1) = 7;
    arr(1, 2) = 2;
    
    arr.sort();

    EXPECT_EQ(arr(0, 0), 9);
    EXPECT_EQ(arr(0, 1), 7);
    EXPECT_EQ(arr(0, 2), 5);
    EXPECT_EQ(arr(1, 0), 3);
    EXPECT_EQ(arr(1, 1), 2);
    EXPECT_EQ(arr(1, 2), 1);

    std::ostringstream oss;
    oss << arr;
    std::string expectedOutput =
        "    9    7    5\n"
        "    3    2    1\n";

    EXPECT_EQ(oss.str(), expectedOutput);
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

