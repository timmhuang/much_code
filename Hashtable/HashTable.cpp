#include "HashTable.h"
#include <iostream>

using std::to_string;

tableEntry::tableEntry(int k, int v) {
    key = k;
    val = new int(v);
}

string tableEntry::toString() {
    string str = "<";
    str += to_string(key) + ", " + to_string(*val) + ">";
    return str;
}

int HashTable::hash(int k) {
    // sdbm hash algorithm
    //int hashAddress = 0;
    //hashAddress = k + (hashAddress << 6) + (hashAddress << 16) - hashAddress;
	int hashAddress = k % 23;
    return hashAddress % capacity;
}

tableEntry* HashTable::getEntry(int k) {
    int bucket = hash(k);
    tableEntry *te = table[bucket];
    while (te && te->key != k) {
        te = te->next;
    }
    return te;
}

void HashTable::addEntry(tableEntry* te, int at) {
    // adding new entries at the head because newly added
    // entries might be accessed again soon
    te->next = table[at];
    table[at] = te;
}

HashTable::HashTable() {
    capacity = INIT_SIZE;
    count = 0;
    table = new tableEntry*[capacity];
    for (int i = 0; i < capacity; ++i) {
        table[i] = NULL;
    }
}

HashTable::~HashTable() {
    for (int i = 0; i < capacity; ++i) {
        tableEntry* te = table[i];
        while (te) {
            tableEntry* next = te->next;
            delete te->val;
            delete te;
            te = next;
        }
    }
}

int HashTable::size() {
	return count;
}

void HashTable::put(int k, int v) {
	// putting to a key that already exist will replace value
    tableEntry* te = getEntry(k);
    if (te) {
		delete te->val;
        te->val = new int(v);
    } else {
        int bucket = hash(k);
        addEntry(new tableEntry(k, v), bucket);
		count += 1;
    }
}

int* HashTable::get(int k) {
    tableEntry* te = getEntry(k);
    if (!te) {
        return NULL;
    }
    return te->val;
}

void HashTable::remove(int k) {
    tableEntry* te = getEntry(k);
    if (!te) return;
    tableEntry* prev = NULL;
    int bucket = hash(k);
    te = table[bucket];
    while (te->key != k) {
        prev = te;
        te = te->next;
    }
    if (!prev) {
        table[bucket] = te->next;
    } else {
        prev->next = te->next;
    }
    delete te->val;
    delete te;
	count -= 1;
}

void HashTable::printAll() {
	std::cout << "--------------------" << std::endl;
    for (int i = 0; i < capacity; ++i) {
        tableEntry* te = table[i];
        std::cout << i << ": ";
        while (te) {
            std::cout << te->toString() << " ";
            te = te->next;
        }
        std::cout << std::endl;
    }
	std::cout << "--------------------" << std::endl;
}