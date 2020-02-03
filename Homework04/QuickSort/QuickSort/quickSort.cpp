/*
Alena Selezneva
*/

#include "quickSort.h"

std::vector<int> quickSort(const std::vector<int>& v) {
	//The way with creating two new vectors each time
	/*if (v.size() <= 1) {
		return v;
	}

	std::vector<int> tmp = v;

	int cur = tmp[tmp.size() - 1];
	std::vector<int> less;
	std::vector<int> greater;
	for (int i = 0; i < tmp.size() - 1; i++) {
		if (tmp[i] > cur) {
			greater.push_back(tmp[i]);
		}
		else {
			less.push_back(tmp[i]);
		}
	}

	less = quickSort(less);
	greater = quickSort(greater);

	less.push_back(cur);
	less.insert(less.end(), greater.begin(), greater.end());

	return less;*/

	//The wrapper for Effitient quick sort
	std::vector<int> tmp = v;
	tmp = quickSortEfficient(tmp, 0, tmp.size() - 1);
	return tmp;

}

std::vector<int> quickSortEfficient(std::vector<int>& v, int l, int r) {
	if (l>=r) {
		return v;
	}

	int cur = v[r];
	int curInd = r;
	int swapTo = r - 1;
	
	for (int i = r - 1; i >= l; i--) {
		if (v[i] > cur) {
			std::swap(v[i], v[curInd]);
			std::swap(v[i], v[swapTo]);
			curInd = swapTo;
			--swapTo;
		}
	}
	v = quickSortEfficient(v, l, curInd - 1);
	v = quickSortEfficient(v, curInd + 1, r);
	return v;
}