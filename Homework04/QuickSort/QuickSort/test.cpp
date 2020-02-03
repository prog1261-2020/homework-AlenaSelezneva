/*
Alena Selezneva
*/

#include "gtest/gtest.h"
#include "quickSort.h"

#include <algorithm>

TEST(TestCaseName, testQsortCallFunc) {
	std::vector<int> v = { 73, 42, 12, 19 };
	auto vresult = quickSort(v);

}

TEST(TestCaseName, testQsortSort01) {
	std::vector<int> v = { 73, 42, 12, 19 };
	std::vector<int> vExpected = { 12, 19, 42, 73 };

	auto vResult = quickSort(v);

	ASSERT_EQ(vResult.size(), vExpected.size());
}

TEST(TestCaseName, testQsortSort02) {
	std::vector<int> v = { 73, 42, 12, 19 };
	std::vector<int> vExpected = { 12, 19, 42, 73 };

	auto vResult = quickSort(v);

	bool isSame = std::equal(vResult.begin(), vResult.end(), vExpected.begin());

	ASSERT_EQ(vResult.size(), vExpected.size());
	ASSERT_TRUE(isSame);
}


TEST(TestCaseName, testQsortSort03) {
	std::vector<int> v = { 73, 42, 12, 19 , 3, 4, 143 };
	std::vector<int> vExpected = { 3, 4, 12, 19, 42, 73 , 143 };

	auto vResult = quickSort(v);

	bool isSame = std::equal(vResult.begin(), vResult.end(), vExpected.begin());

	ASSERT_EQ(vResult.size(), vExpected.size());
	ASSERT_TRUE(isSame);
}
