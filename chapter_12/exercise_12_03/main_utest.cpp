#include "headers/CommissionEmployee.hpp"
#include "headers/BasePlusCommissionEmployee.hpp"
#include <gtest/gtest.h>

TEST(CommissionEmployeeTest, ConstructorAndGetters)
{
    CommissionEmployee ce("Artak", "Avetisyan", "123-45-6789", 5000.0, 0.04);

    EXPECT_EQ(ce.getName(), "Artak");
    EXPECT_EQ(ce.getSurname(), "Avetisyan");
    EXPECT_EQ(ce.getSocialSecurityCode(), "123-45-6789");
    EXPECT_DOUBLE_EQ(ce.getGrossSales(), 5000.0);
    EXPECT_DOUBLE_EQ(ce.getRate(), 0.04);
}

TEST(CommissionEmployeeTest, CalculateSalary)
{
    CommissionEmployee ce("Artak", "Avetisyan", "123-45-6789", 5000.0, 0.04);
    double expected = 5000.0 * 0.04;
    EXPECT_DOUBLE_EQ(ce.salary(), expected);
}

TEST(BasePlusCommissionEmployeeTest, ConstructorAndGetters)
{
    BasePlusCommissionEmployee bpce("Ani", "Petrosyan", "987-65-4321",
                                    6000.0, 1000.0, 0.05);

    EXPECT_EQ(bpce.getName(), "Ani");
    EXPECT_EQ(bpce.getSurname(), "Petrosyan");
    EXPECT_EQ(bpce.getSocialSecurityCode(), "987-65-4321");
    EXPECT_DOUBLE_EQ(bpce.getGrossSales(), 6000.0);
    EXPECT_DOUBLE_EQ(bpce.getRate(), 0.05);
    EXPECT_DOUBLE_EQ(bpce.getBaseSalary(), 1000.0);
}

TEST(BasePlusCommissionEmployeeTest, CalculateSalary)
{
    BasePlusCommissionEmployee bpce("Ani", "Petrosyan", "987-65-4321",
                                    6000.0, 1000.0, 0.05);

    double expected = 1000.0 + (6000.0 * 0.05);
    EXPECT_DOUBLE_EQ(bpce.salary(), expected);
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

