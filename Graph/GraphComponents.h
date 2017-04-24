#ifndef GRAPH_COMPONENT_H
#define GRAPH_COMPONENT_H

struct edge {
	int from;
	int to;
	int cost;
	edge(int f, int t, int c) : from(f), to(t), cost(c) {}
};

#endif