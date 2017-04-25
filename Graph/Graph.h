#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <unordered_map>
#include <queue>
#include "GraphComponents.h"

using std::vector;
using std::unordered_map;
using std::priority_queue;

class Graph {
	int vertexCount;
	vector<vertex> vertices;
	vector<edge> edges;
	vector<vector<int>> shortestPaths;
	bool prepareDijkstra(vector<vector<int>>&, unordered_map<int, unordered_map<int, int>>&);
public:
	Graph();
	Graph(int, vector<edge>&);
	int getVertexCount();
	const vector<vertex>& getVertices() const;
	const vector<edge>& getEdges() const;
	vector<int> getPath(int, int);
	bool bellmanFord(int);
	bool dijkstra(int);
};

#endif