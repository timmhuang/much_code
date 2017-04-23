#include <iostream>
#include <vector>
#include "Deque.h"

using std::vector;

int main() {
	Deque* d = new Deque();
	vector<int> data = { 1, 2, 3 };
	for (int n : data) {
		cout << "Appending data " << n << " to head" << endl;
		d->push_front(n);
	}
	d->printAll();

	int count = 2;
	cout << "Removing " << count << " data from head" << endl;
	for (int i = 0; i < count; ++i) {
		d->pop_front();
	}
	d->printAll();

	for (int n : data) {
		int v = n + 3;
		cout << "Appending data " << v << " to back" << endl;
		d->push_back(v);
	}
	d->printAll();

	cout << "Removing " << count << " data from tail" << endl;
	for (int i = 0; i < count; ++i) {
		d->pop_back();
	}
	d->printAll();

	cout << "Removing " << count << " from tail then accessing head" << endl;
	for (int i = 0; i < count; ++i) {
		d->pop_back();
	}
	try {
		d->front();
	} catch (EmptyDequeException e) {
		cout << "Caught Exception: \n\t" << e.what() << endl;
	}
	d->printAll();

	delete d;
	cout << endl << "Press enter to exit" << endl;
	string s;
	std::getline(std::cin, s);
	return 0;
}