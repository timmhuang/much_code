#include "Graph.h"

Graph::Graph() {}

Graph::Graph(int v, vector<edge>& e) : vertices(v), edges(e) {}

vector<int> Graph::bellmanFord(int start) {
	vector<int> costs(vertices, INT_MAX);
	if (start < 0 || start >= vertices) {
		return costs;
	}
	vector<int> predecessors(vertices, -1);
	costs[start] = 0;
	for (int i = 0; i < vertices - 1; ++i) {
		for (edge e : edges) {
			long long dist = (long long)costs[e.from] + e.cost;
			if (costs[e.to] <= dist) {
				continue;
			}
			costs[e.to] = dist;
			predecessors[e.to] = e.from;
		}
	}

	for (edge e : edges) {
		// detect negative-weight cycle
		if (costs[e.to] > costs[e.from] + e.cost) {
			return vector<int>();
		}
	}
	return costs;
}