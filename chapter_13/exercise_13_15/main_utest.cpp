#include <gtest/gtest.h>
#include "headers/Person.hpp"
#include "headers/Package.hpp"
#include "headers/TwoDayPackage.hpp"
#include "headers/OverNightPackage.hpp"
#include <vector>
#include <iostream>

TEST(PersonTest, ConstructorAndGetters)
{
    Person sender("Alice Smith", "456 Oak St", "Gyumri", "Shirak", "0020");
    EXPECT_EQ(sender.getName(), "Alice Smith");
    EXPECT_EQ(sender.getAddress(), "456 Oak St");
    EXPECT_EQ(sender.getCity(), "Gyumri");
    EXPECT_EQ(sender.getState(), "Shirak");
    EXPECT_EQ(sender.getZIP(), "0020");
}

TEST(PackageTest, CalculateCost)
{
    Person sender("Tom", "Street 1", "CityX", "StateX", "1001");
    Person recipient("Jerry", "Street 2", "CityY", "StateY", "1002");
    Package pkg(sender, recipient, 12.0, 0.75);

    EXPECT_DOUBLE_EQ(pkg.getWeight(), 12.0);
    EXPECT_DOUBLE_EQ(pkg.getCostPerOunce(), 0.75);
    EXPECT_DOUBLE_EQ(pkg.calculateCost(), 9.0);
}

TEST(PackageTest, SettersWork)
{
    Person sender("Tom", "Street 1", "CityX", "StateX", "1001");
    Person recipient("Jerry", "Street 2", "CityY", "StateY", "1002");
    Package pkg(sender, recipient, 6, 1.5);
    pkg.setWeight(9);
    pkg.setCostPerOunce(2.0);
    EXPECT_DOUBLE_EQ(pkg.getWeight(), 9);
    EXPECT_DOUBLE_EQ(pkg.getCostPerOunce(), 2.0);
    EXPECT_DOUBLE_EQ(pkg.calculateCost(), 18);
}

TEST(TwoDayPackageTest, FlatFeeIncluded)
{
    Person sender("Bob", "789 Pine St", "Vanadzor", "Lori", "0030");
    Person recipient("Anna", "321 Elm St", "Yerevan", "Yerevan", "0040");
    TwoDayPackage pkg(sender, recipient, 15, 0.6, 3.0);
    EXPECT_DOUBLE_EQ(pkg.getFlatFee(), 3.0);
    EXPECT_DOUBLE_EQ(pkg.calculateCost(), 15 * 0.6 + 3.0);
}

TEST(TwoDayPackageTest, CopyConstructorWorks)
{
    Person sender("Mike", "Street 7", "CityZ", "StateZ", "0050");
    Person recipient("Sara", "Street 8", "CityW", "StateW", "0060");
    TwoDayPackage pkg1(sender, recipient, 8, 1.2, 4);
    TwoDayPackage pkg2(pkg1);

    EXPECT_DOUBLE_EQ(pkg2.getFlatFee(), pkg1.getFlatFee());
    EXPECT_DOUBLE_EQ(pkg2.calculateCost(), pkg1.calculateCost());
}

TEST(OverNightPackageTest, ExtraCostIncluded)
{
    Person sender("Liam", "Street 9", "CityA", "StateA", "0070");
    Person recipient("Olivia", "Street 10", "CityB", "StateB", "0080");
    OverNightPackage pkg(sender, recipient, 20, 0.4, 5.0);
    EXPECT_DOUBLE_EQ(pkg.getExtraCost(), 5.0);
    EXPECT_DOUBLE_EQ(pkg.calculateCost(), 20 * 0.4 + 5.0);
}

TEST(OverNightPackageTest, CopyConstructorWorks)
{
    Person sender("Noah", "Street 11", "CityC", "StateC", "0090");
    Person recipient("Emma", "Street 12", "CityD", "StateD", "0100");
    OverNightPackage pkg1(sender, recipient, 7, 0.8, 2);
    OverNightPackage pkg2(pkg1);

    EXPECT_DOUBLE_EQ(pkg2.getExtraCost(), pkg1.getExtraCost());
    EXPECT_DOUBLE_EQ(pkg2.calculateCost(), pkg1.calculateCost());
}

TEST(PackageTest, PolymorphicTest)
{
    Person sender("Ethan", "1st Ave", "CityE", "StateE", "0110");
    Person recipient("Sophia", "2nd Ave", "CityF", "StateF", "0120");

    std::vector<Package*> packages;

    packages.push_back(new Package(sender, recipient, 5.0, 1.0));
    packages.push_back(new TwoDayPackage(sender, recipient, 7.0, 1.5, 2.0));
    packages.push_back(new OverNightPackage(sender, recipient, 3.0, 2.0, 1.0));

    double totalCost = 0.0;

    for (size_t i = 0; i < packages.size(); ++i) {
        std::cout << "________________________\n";
        packages[i]->print();
        totalCost += packages[i]->calculateCost();
        std::cout << "________________________\n";
    }

    std::cout << "Total Cost = " << totalCost << std::endl;

    for (size_t i = 0; i < packages.size(); ++i) {
        delete packages[i];
    }
}

int
main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

