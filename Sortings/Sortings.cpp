#include <iostream>
#include <string>
#include "Sortings.h"

using std::cout;
using std::endl;
using std::cin;


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