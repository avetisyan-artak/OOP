#include "headers/String.hpp"
#include <gtest/gtest.h>
#include <sstream>

static std::string toStdString(const String& s)
{
    std::ostringstream out;
    out << s;
    return out.str();
}

TEST(StringTest, ConstructorFromCString)
{
    String greeting("Salam");
    EXPECT_EQ(greeting.getLength(), 5);
    EXPECT_EQ(toStdString(greeting), "Salam");
}

TEST(StringTest, CopyConstructor)
{
    String first("Khosh");
    String copy(first);
    EXPECT_EQ(copy.getLength(), 5);
    EXPECT_EQ(toStdString(copy), "Khosh");
}

TEST(StringTest, EmptyString)
{
    String emptyStr("");
    EXPECT_EQ(emptyStr.getLength(), 0);
    EXPECT_EQ(toStdString(emptyStr), "");
}

TEST(StringTest, ConcatenationBasic)
{
    String part1("Tech");
    String part2("Hub");
    String combined = part1 + part2;
    EXPECT_EQ(combined.getLength(), 7);
    EXPECT_EQ(toStdString(combined), "TechHub");
}

TEST(StringTest, ConcatenationWithEmptyLeft)
{
    String empty("");
    String word("AI");
    String result = empty + word;
    EXPECT_EQ(result.getLength(), 2);
    EXPECT_EQ(toStdString(result), "AI");
}

TEST(StringTest, ConcatenationWithEmptyRight)
{
    String word("Code");
    String empty("");
    String result = word + empty;
    EXPECT_EQ(result.getLength(), 4);
    EXPECT_EQ(toStdString(result), "Code");
}

TEST(StringTest, PlusEqualOperator)
{
    String s1("Data");
    String s2("Lab");
    s1 += s2;
    EXPECT_EQ(s1.getLength(), 7);
    EXPECT_EQ(toStdString(s1), "DataLab");
}

TEST(StringTest, SelfConcatenation)
{
    String s("Hi");
    s += s;
    EXPECT_EQ(s.getLength(), 4);
    EXPECT_EQ(toStdString(s), "HiHi");
}

TEST(StringTest, OriginalStringsUnchangedAfterPlus)
{
    String first("Learn");
    String second("JS");
    String result = first + second;
    EXPECT_EQ(toStdString(first), "Learn");
    EXPECT_EQ(toStdString(second), "JS");
    EXPECT_EQ(toStdString(result), "LearnJS");
}

TEST(StringTest, EqualityOperator)
{
    String a("Ok");
    String b("Ok");
    EXPECT_TRUE(a == b);
}

TEST(StringTest, InequalityOperator)
{
    String a("No");
    String b("Yes");
    EXPECT_TRUE(a != b);
}

TEST(StringTest, LessThanOperator)
{
    String x("A");
    String y("B");
    EXPECT_TRUE(x < y);
}

TEST(StringTest, GreaterThanOperator)
{
    String alpha("Z");
    String beta("A");
    EXPECT_TRUE(alpha > beta);
}

TEST(StringTest, LessThanOrEqualOperator)
{
    String a("One");
    String b("One");
    EXPECT_TRUE(a <= b);
}

TEST(StringTest, GreaterThanOrEqualOperator)
{
    String a("Two");
    String b("Two");
    EXPECT_TRUE(a >= b);
}

TEST(StringTest, SubstringOperator)
{
    String s("OpenSource");
    String sub = s(0, 4);
    EXPECT_EQ(toStdString(sub), "Open");
}

TEST(StringTest, IndexOperatorGet)
{
    String s("Hello");
    EXPECT_EQ(s[0], 'H');
    EXPECT_EQ(s[4], 'o');
}

TEST(StringTest, IndexOperatorSet)
{
    String s("World");
    s[0] = 'P';
    EXPECT_EQ(toStdString(s), "Porld");
}

TEST(StringTest, CopyAssignmentOperator)
{
    String left("Left");
    String right("Right");
    right = left;
    EXPECT_EQ(toStdString(right), "Left");
    EXPECT_EQ(right.getLength(), 4);
}

TEST(StringTest, SelfAssignment)
{
    String s("Same");
    s = s;
    EXPECT_EQ(toStdString(s), "Same");
    EXPECT_EQ(s.getLength(), 4);
}

TEST(StringTest, StreamOutputOperator)
{
    String s("PrintMe");
    std::ostringstream out;
    out << s;
    EXPECT_EQ(out.str(), "PrintMe");
}

TEST(StringTest, StreamInputOperator)
{
    String s("");
    std::istringstream in("InputTest");
    in >> s;
    EXPECT_EQ(toStdString(s), "InputTest");
}

TEST(StringTest, ChainedConcatenation)
{
    String a("Red");
    String b("Blue");
    String c("Green");
    String combined = a + b + c;
    EXPECT_EQ(combined.getLength(), 12);
    EXPECT_EQ(toStdString(combined), "RedBlueGreen");
}

int
main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

