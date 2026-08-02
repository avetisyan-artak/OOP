#include "headers/Complex.hpp"
#include <gtest/gtest.h>

TEST(ComplexTest, DefaultConstructorTest)
{
    Complex number;

    EXPECT_EQ(number.getRealPart(), 0.0);
    EXPECT_EQ(number.getImaginaryPart(), 0.0);
}

TEST(ComplexTest, CopyConstructor)
{
    Complex number1(3.4, 5.4);
    Complex number2(number1);

    EXPECT_EQ(number2.getRealPart(), 3.4);
    EXPECT_EQ(number2.getImaginaryPart(), 5.4);
}

TEST(ComplexTest, setterFunctionTest)
{
    Complex number1(0.0, 0.0);

    number1.setRealPart(4.5);
    number1.setImaginaryPart(5.6);

    Complex number2(0.0, 0.0);

    number2.setRealPart(59.3);
    number2.setImaginaryPart(4.1);

    EXPECT_EQ(number1.getRealPart(), 4.5);
    EXPECT_EQ(number1.getImaginaryPart(), 5.6);
    EXPECT_EQ(number2.getRealPart(), 59.3);
    EXPECT_EQ(number2.getImaginaryPart(), 4.1);
}

TEST(ComplexTest, sumOfComplexNumbers)
{
    Complex number1(4.5, 6.5);
    Complex number2(6.7, 8.9);

    Complex result = number1.sumOfNumbers(number2);

    EXPECT_EQ(result.getRealPart(), 11.2);
    EXPECT_EQ(result.getImaginaryPart(), 15.4);
}

TEST(ComplexTest, subOfComplexNumber)
{
    Complex number1(4.5, 9.5);
    Complex number2(6.7, 0.5);

    Complex result = number1.subOfNumbers(number2);

    EXPECT_EQ(result.getRealPart(), -2.2);
    EXPECT_EQ(result.getImaginaryPart(), 9.0);
}

TEST(ComplexTest, SubtractionNegativeTest)
{
    Complex number1(-1.5, -2.5);
    Complex number2(3.0, 4.0);

    Complex result = number1.subOfNumbers(number2);

    EXPECT_EQ(result.getRealPart(), -4.5);
    EXPECT_EQ(result.getImaginaryPart(), -6.5);
}

TEST(ComplexTest, multiplication)
{
    Complex number1(5.4, 9.0);
    Complex number2(1.0, 2.0);

    Complex result = number1.multiplication(number2);

    EXPECT_EQ(result.getRealPart(), -12.6);
    EXPECT_EQ(result.getImaginaryPart(), 19.8);
}

TEST(ComplexTest, MultiplicationTest)
{
    Complex number1(2.0, 3.0);
    Complex number2(4.0, 5.0);

    Complex result = number1.multiplication(number2);

    EXPECT_EQ(result.getRealPart(), -7.0);
    EXPECT_EQ(result.getImaginaryPart(), 22.0);
}

TEST(ComplexTest, displayTest)
{
    Complex number1(4.6, 5.6);

    testing::internal::CaptureStdout();
    number1.printResult();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "4.6 + 5.6i\n");
}

int
main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

