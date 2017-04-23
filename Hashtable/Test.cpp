#include <iostream>
#include <vector>
#include "HashTable.h"

using std::vector;

int main() {
	HashTable *t = new HashTable();
	for (int i = 0; i < 8; ++i) {
		t->put(i * i, i);
	}
	t->printAll();

	for (int i = 0; i < 8; ++i) {
		int k = i * i;
		std::cout << "value for key: " << k << " is: " << *t->get(k) <<std::endl;
	}

	// test getting entries
	vector<int> arr = { 4, 36, 43 };
	for (int n : arr) {
		int* res = t->get(n);
		std::cout << "Key: " << n << " returns: ";
		if (res) {
			std::cout << *res << std::endl;
		} else {
			std::cout << "NULL" << std::endl;
		}
	}
	std::cout << std::endl;

	// test removing entries
	arr = { 16, 49, 9 };
	for (int n : arr) {
		std::cout << "Removing key: " << n << std::endl;
		t->remove(n);
		t->printAll();
	}
	std::cout << std::endl;

	// test adding entries
	arr = { 23, 13, 25 };
	for (int n : arr) {
		std::cout << " Adding entry <" << n << ", 1>" << std::endl;
		t->put(n, 1);
		t->printAll();
	}

	std::cout << "Press enter to exit" << std::endl;
	string a;
	std::getline(std::cin, a);
	return 0;
}