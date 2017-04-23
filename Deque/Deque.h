/*
Simple integer deque implementation using doubly linked list
*/
#ifndef DEQUE_H
#define DEQUE_H

#include <iostream>
#include <string>
#include <exception>

using std::cout;
using std::endl;
using std::string;
using std::runtime_error;

struct EmptyDequeException : public runtime_error {
	EmptyDequeException() : runtime_error("Cannot access element in empty deque") {}
};

struct dequeEntry {
	int val;
	dequeEntry* prev;
	dequeEntry* next;
	dequeEntry(int v) : val(v), prev(NULL), next(NULL) {}
	string toString();
};

class Deque {
	dequeEntry* head;
	dequeEntry* tail;
	int size;

public:
	Deque();
	~Deque();
	void push_front(int v);
	void push_back(int v);
	int front();
	int back();
	void pop_front();
	void pop_back();
	void printAll();
};

#endif