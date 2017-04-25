#include <utility>
#include "Graph.h"

using std::reverse;

Graph::Graph() {}

Graph::Graph(int v, vector<edge>& e) : vertexCount(v), edges(e) {
	for (int i = 0; i < v; ++i) {
		vertices.push_back(vertex(i, INT_MAX));
	}
}

int Graph::getVertexCount() {
	return vertexCount;
}

const vector<vertex>& Graph::getVertices() const {
	return vertices;
}

const vector<edge>& Graph::getEdges() const {
	return edges;
}

vector<int> Graph::getPath(int from, int to) {
	vector<int> path = { to };
	while (vertices[to].pred != -1 && vertices[to].pred != from) {
		path.push_back(vertices[to].pred);
		to = vertices[to].pred;
	}
	if (vertices[to].pred != -1) {
		path.push_back(vertices[to].pred);
	}
	reverse(path.begin(), path.end());
	return path;
}

bool Graph::bellmanFord(int start) {
	if (start < 0 || start >= vertexCount) {
		throw "Invalid starting vertex";
	}

	vertices[start].val= 0;
	for (int i = 0; i < vertexCount - 1; ++i) {
		for (edge e : edges) {
			long long dist = (long long)vertices[e.from].val + e.cost;
			if (vertices[e.to].val <= dist) {
				continue;
			}
			vertices[e.to].val = dist;
			vertices[e.to].pred = e.from;
		}
	}

	for (edge e : edges) {
		// detect negative-weight cycle
		if (vertices[e.to].val > vertices[e.from].val + e.cost) {
			return false;
		}
	}
	return true;
}

bool Graph::prepareDijkstra(vector<vector<int>>& ajdList, unordered_map<int, unordered_map<int, int>>& cost) {
	for (edge e : edges) {
		ajdList[e.from].push_back(e.to);
		cost[e.from][e.to] = e.cost;
		if (e.cost < 0) {
			return false;
		}
	}
	return true;
}

bool Graph::dijkstra(int start) {
	if (start < 0 || start >= vertexCount) {
		throw "Invalid starting vertex";
	}

	vector<vector<int>> adjList(vertexCount);
	unordered_map<int, unordered_map<int, int>> cost;
	if (!prepareDijkstra(adjList, cost)) {
		printf("Found negative weighted edge, cannot initialize Dijkstra's\n");
		return false;
	}

	/* algorithm body */
	for (vertex v : vertices) {
		v.val = INT_MAX;
		v.pred = -1;
	}
	priority_queue<vertex, vector<vertex>, vertexMinHeapComparator> q;
	vertices[start].val = 0;
	q.push(vertices[start]);

	while (!q.empty()) {
		vertex cur = q.top();
		q.pop();
		for (int v : adjList[cur.id]) {
			int c = cur.val + cost[cur.id][v];
			if (vertices[v].val <= c) {
				continue;
			}
			vertices[v].val = c;
			vertices[v].pred = cur.id;
			q.push(vertices[v]);
		}
	}
	return true;
}