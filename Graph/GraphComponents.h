#ifndef GRAPH_COMPONENT_H
#define GRAPH_COMPONENT_H

struct vertex {
	int id;
	int val;
	int pred;
	vertex(int i, int v) : id(i), val(v) {
		pred = -1;
	}
};

struct vertexMinHeapComparator {
	bool operator()(const vertex& a, const vertex& b) {
		return a.val > b.val;
	}
};

struct edge {
	int from;
	int to;
	int cost;
	edge(int f, int t, int c) : from(f), to(t), cost(c) {}
};

#endif