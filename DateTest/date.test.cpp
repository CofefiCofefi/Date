#include "gtest/gtest.h"
#include "date.hpp"


TEST(TestingTester, Test1) {
	int x = Jonah(2);
	EXPECT_EQ(x, 4);
}

TEST(TestingTester, Test2) {
	int x = Jonah(3);
	EXPECT_EQ(x, 6);
}

TEST(TestingTester, Test3) {
	int x = Jonah(5);
	EXPECT_EQ(x, 10);
}