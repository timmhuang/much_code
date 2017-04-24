#include <iostream>
#include <string>
#include "Sortings.h"

using std::cout;
using std::endl;
using std::cin;

void Sortings::swap(int a, int b, vector<int>& nums) {
	int temp = nums[a];
	nums[a] = nums[b];
	nums[b] = temp;
}

void Sortings::countingSort(vector<int>& input, int l, int k) {
	int range = k - l + 1;
	vector<int> count(range + 1, 0);
	for (int i : input) {
		count[i + -l] += 1;
	}
	for (int i = 1; i <= range; ++i) {
		count[i] += count[i - 1];
	}
	vector<int> result(input.size());
	for (int i = input.size() - 1; i >= 0; --i) {
		int pos = input[i] + -l;
		result[count[pos] - 1] = input[i];
		count[pos] -= 1;
	}
	input = result;
}

/* Quick sort functions */
void Sortings::quickSort(vector<int>& nums) {
	quickSortHelper(0, nums.size() - 1, nums);
}

void Sortings::quickSortHelper(int s, int e, vector<int>& nums) {
	if (s >= e) {
		return;
	}
	int sorted = partition(s, e, nums);
	quickSortHelper(s, sorted - 1, nums);
	quickSortHelper(sorted + 1, e, nums);
}

int Sortings::partition(int s, int e, vector<int>& nums) {
	int pivotIdx = s + (rand() % (e - s + 1));
	swap(pivotIdx, e, nums);
	for (int i = s; i < e; ++i) {
		if (nums[i] <= nums[e]) {
			swap(s, i, nums);
			s += 1;
		}
	}
	swap(s, e, nums);
	return s;
}
/* end of quick sort */

/* merge sort functions */
void Sortings::mergeSort(vector<int>& nums) {
	mergeSortHelper(0, nums.size() - 1, nums);
}

void Sortings::mergeSortHelper(int s, int e, vector<int>& nums) {
	if (s >= e) {
		return;
	}
	int mid = s + (e - s) / 2;
	mergeSortHelper(s, mid, nums);
	mergeSortHelper(mid + 1, e, nums);
	vector<int> merged;
	int a = s;
	int b = mid + 1;
	while (a <= mid && b <= e) {
		if (nums[a] < nums[b]) {
			merged.push_back(nums[a]);
			a += 1;
		}
		else {
			merged.push_back(nums[b]);
			b += 1;
		}
	}
	for (a; a <= mid; ++a) {
		merged.push_back(nums[a]);
	}
	for (b; b <= e; ++b) {
		merged.push_back(nums[b]);
	}
	int k = 0;
	for (int i = s; i <= e; ++i) {
		nums[i] = merged[k];
		k += 1;
	}
}

/* end of merge sort */