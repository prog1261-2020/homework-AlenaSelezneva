/*
Alena Selezneva
*/

#include "SortFunctions.h"
#include <vector>

std::vector<int> bsort(const std::vector<int>& v) {
	std::vector<int> tmp;
	tmp = v;

	for (int i = 0; i < tmp.size() - 1; i++) {
		bool flag = true;
		for (int j = 0; j < tmp.size() - 1 - i; j++) {
			if (tmp[j] > tmp[j + 1]) {
				std::swap(tmp[j], tmp[j + 1]);
				flag = false;
			}
		}
		if (flag)
			return tmp;
	}

	return tmp;
}

std::vector<int> selectionSort(const std::vector<int>& v) {
	std::vector<int> tmp;
	tmp = v;

	for (int i = 0; i < tmp.size() - 1; i++) {
		int min_ = INT32_MAX;
		int ind = -1;

		for (int j = i; j < tmp.size(); j++) {
			if (tmp[j] < min_) {
				min_ = tmp[j];
				ind = j;
			}
		}
			if (ind != -1) {
				std::swap(tmp[i], tmp[ind]);
			}
		}
	return tmp;
}
