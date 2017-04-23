#include "Deque.h"

using std::to_string;

string dequeEntry::toString() {
	return to_string(val);
}

Deque::Deque() {
	head = NULL;
	tail = NULL;
	size = 0;
}

Deque::~Deque() {
	while (head) {
		dequeEntry* next = head->next;
		delete head;
		head = next;
	}
}

void Deque::push_front(int v) {
	dequeEntry* node = new dequeEntry(v);
	if (size == 0) {
		tail = node;
		head = node;
	} else {
		node->next = head;
		head->prev = node;
		head = node;
	}
	size += 1;
}

void Deque::push_back(int v) {
	dequeEntry* node = new dequeEntry(v);
	if (size == 0) {
		tail = node;
		head = node;
	} else {
		tail->next = node;
		node->prev = tail;
		tail = node;
	}
	size += 1;
}

int Deque::front() {
	if (size == 0) {
		throw EmptyDequeException();
	}
	return head->val;
}

int Deque::back() {
	if (size == 0) {
		throw EmptyDequeException();
	}
	return tail->val;
}

void Deque::pop_front() {
	if (size == 0) {
		throw EmptyDequeException();
	}
	dequeEntry* rem = head;
	if (size == 1) {
		head = NULL;
		tail == NULL;
	} else {
		head = head->next;
		head->prev = NULL;
	}
	delete rem;
	size -= 1;
}

void Deque::pop_back() {
	if (size == 0) {
		throw EmptyDequeException();
	}
	dequeEntry* rem = tail;
	if (size == 1) {
		head = NULL;
		tail = NULL;
	} else {
		tail = tail->prev;
		tail->next = NULL;
	}
	delete rem;
	size -= 1;
}

void Deque::printAll() {
	cout << "\nCurrent Size: " << size << endl;
	dequeEntry* de = head;
	while (de) {
		cout << de->val;
		if (de->next) {
			cout << " <-> ";
		}
		de = de->next;
	}
	cout << endl << endl;;
}