/*
Alena Selezneva
*/

#include "gtest/gtest.h"
#include <vector>
#include "SortFunctions.h"
#include <algorithm>

TEST(TestCaseName, testBSsortCallFunc) {
	std::vector<int> v = { 73, 42, 12, 19 };
	auto vresult = bsort(v);

}

TEST(TestCaseName, testBSsortSort01) {
	std::vector<int> v = { 73, 42, 12, 19 };
	std::vector<int> vExpected = { 12, 19, 42, 73 };

	auto vResult = bsort(v);

	ASSERT_EQ(vResult.size(), vExpected.size());
}

TEST(TestCaseName, testBSsortSort02) {
	std::vector<int> v = { 73, 42, 12, 19 };
	std::vector<int> vExpected = { 12, 19, 42, 73 };

	auto vResult = bsort(v);

	bool isSame = std::equal(vResult.begin(), vResult.end(), vExpected.begin());

	ASSERT_EQ(vResult.size(), vExpected.size());
	ASSERT_TRUE(isSame);
}


TEST(TestCaseName, testBSsortSort03) {
	std::vector<int> v = { 73, 42, 12, 19 , 3, 4, 143};
	std::vector<int> vExpected = { 3, 4, 12, 19, 42, 73 , 143};

	auto vResult = bsort(v);

	bool isSame = std::equal(vResult.begin(), vResult.end(), vExpected.begin());

	ASSERT_EQ(vResult.size(), vExpected.size());
	ASSERT_TRUE(isSame);
}

TEST(TestCaseName, testSSsortSort03) {
	std::vector<int> v = { 73, 42, 12, 19 , 3, 4, 143 };
	std::vector<int> vExpected = { 3, 4, 12, 19, 42, 73 , 143 };

	auto vResult = selectionSort(v);

	bool isSame = std::equal(vResult.begin(), vResult.end(), vExpected.begin());

	ASSERT_EQ(vResult.size(), vExpected.size());
	ASSERT_TRUE(isSame);
}

