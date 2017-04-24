#include <iostream>
#include <vector>
#include <string>
#include <exception>
#include <chrono>
#include "Sortings.h"

using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;
using ns = std::chrono::nanoseconds;
using cclock = std::chrono::high_resolution_clock;

const double NS_IN_SECOND = 1000000000.0;

void printArray(vector<int>& nums) {
	for (int n : nums) {
		cout << n << " ";
	}
	cout << endl;
}

int main(int argc, const char** argv) {
	int arrSize = 5000;
	if (argc > 2) {
		throw "Too many arguments";
	} else if (argc == 2) {
		arrSize = atoi(argv[1]);
	}
	Sortings sort;
	vector<int> nums;
	for (int i = 0; i < arrSize; ++i) {
		nums.push_back(rand() % 100 - 50);
	}
	vector<int> numsCopy = nums;

	cout << "Input: " << endl;
	printArray(nums);
	
	cout << "Quick Sorting... " << endl;
	auto start = cclock::now();
	sort.quickSort(nums);
	auto diff = cclock::now() - start;
	long long nanoseconds = std::chrono::duration_cast<ns>(diff).count();
	cout << "Done!" << endl;
	cout << "Time spent: " << nanoseconds / NS_IN_SECOND << " seconds" << endl;

	cout << "Press enter to exit" << endl;
	string s;
	std::getline(cin, s);
	return 0;
}