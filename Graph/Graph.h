#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "GraphComponents.h"

using std::vector;

class Graph {
	int vertices;
	vector<edge> edges;
public:
	Graph();
	Graph(int, vector<edge>&);
	vector<int> bellmanFord(int);
};

#endif