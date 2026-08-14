#include <gtest/gtest.h>
#include "headers/Package.hpp"
#include "headers/TwoDayPackage.hpp"
#include "headers/OverNightPackage.hpp"

TEST(PackageTest, CalculateCost)
{
    Person sender("John", "123 Street", "CityA", "StateA", "11111");
    Person recipient("Mike", "456 Avenue", "CityB", "StateB", "22222");

    Package p(sender, recipient, 10.0, 2.5);
    EXPECT_DOUBLE_EQ(p.calculateCost(), 25.0);

    p.setWeight(5.0);
    p.setCostPerOunce(3.0);
    EXPECT_DOUBLE_EQ(p.calculateCost(), 15.0);
}

TEST(TwoDayPackageTest, CalculateCostWithFlatFee)
{
    Person sender("John", "123 Street", "CityA", "StateA", "11111");
    Person recipient("Mike", "456 Avenue", "CityB", "StateB", "22222");

    TwoDayPackage td(sender, recipient, 10.0, 2.0, 5.0);
    EXPECT_DOUBLE_EQ(td.calculateCost(), 25.0);

    td.setFlatFee(3.0);
    EXPECT_DOUBLE_EQ(td.calculateCost(), 23.0);
}

TEST(OverNightPackageTest, CalculateCostWithExtraCost)
{
    Person sender("John", "123 Street", "CityA", "StateA", "11111");
    Person recipient("Mike", "456 Avenue", "CityB", "StateB", "22222");

    OverNightPackage on(sender, recipient, 8.0, 3.0, 10.0);
    EXPECT_DOUBLE_EQ(on.calculateCost(), 34.0);

    on.setExtraCost(5.0);
    EXPECT_DOUBLE_EQ(on.calculateCost(), 29.0);
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

