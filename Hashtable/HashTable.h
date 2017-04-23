#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#include <string>

using std::string;

struct tableEntry {
    int key;
    int* val;
    tableEntry* next;
    tableEntry(int k, int v);
	string toString();
};

class HashTable {
    const int INIT_SIZE = 8;
    int capacity;
    unsigned count;
    tableEntry **table;

    int hash(int k);
    tableEntry* getEntry(int k);
    void addEntry(tableEntry* te, int at);
public:
    HashTable();
    ~HashTable();
	int size();
    void put(int k, int v);
    int* get(int k);
    void remove(int k);
    void printAll();
};

#endif