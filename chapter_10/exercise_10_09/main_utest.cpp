#include "headers/IntegerSet.hpp"
#include <gtest/gtest.h>

TEST(IntegerSetTest, DefaultConstructor)
{
    IntegerSet set;
    IntegerSet emptySet;
    EXPECT_TRUE(set.isEqualTo(emptySet));
}

TEST(IntegerSetTest, AddRemoveNumbers)
{
    IntegerSet set;
    set.insert(7);
    set.insert(25);

    IntegerSet expected;
    expected.insert(7);
    expected.insert(25);

    EXPECT_TRUE(set.isEqualTo(expected));

    set.deleteElement(7);
    expected.deleteElement(7);

    EXPECT_TRUE(set.isEqualTo(expected));
}

TEST(IntegerSetTest, ArrayConstructor)
{
    int nums[] = {4, 8, 12};
    IntegerSet set(nums, 3);

    IntegerSet expected;
    expected.insert(4);
    expected.insert(8);
    expected.insert(12);

    EXPECT_TRUE(set.isEqualTo(expected));
}

TEST(IntegerSetTest, UnionOperation)
{
    IntegerSet setA;
    setA.insert(1);
    setA.insert(5);

    IntegerSet setB;
    setB.insert(3);
    setB.insert(5);

    IntegerSet result = setA.unionOfSets(setB);

    IntegerSet expected;
    expected.insert(1);
    expected.insert(3);
    expected.insert(5);

    EXPECT_TRUE(result.isEqualTo(expected));
}

TEST(IntegerSetTest, IntersectionOperation)
{
    IntegerSet setA;
    setA.insert(2);
    setA.insert(4);

    IntegerSet setB;
    setB.insert(4);
    setB.insert(6);

    IntegerSet result = setA.insertSectionOfSets(setB);

    IntegerSet expected;
    expected.insert(4);

    EXPECT_TRUE(result.isEqualTo(expected));
}

TEST(IntegerSetTest, EqualityCheck)
{
    IntegerSet set1;
    set1.insert(9);

    IntegerSet set2;
    set2.insert(9);

    EXPECT_TRUE(set1.isEqualTo(set2));

    set2.insert(10);
    EXPECT_FALSE(set1.isEqualTo(set2));
}

int
main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

