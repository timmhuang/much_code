#ifndef SORTINGS_H
#define SORTINGS_H
#include <vector>

using std::vector;

class Sortings{
	void swap(int, int, vector<int>&);
	int partition(int, int, vector<int>&);
	void quickSortHelper(int, int, vector<int>&);
public:
	void countingSort(vector<int>&, int, int);
	void quickSort(vector<int>&);
};

#endif