#include <iostream>
#include <string>
#include <fstream>
#include "Graph.h"

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::string;
using std::getline;

vector<int> extractIntTokens(string& s) {
	vector<int> result;
	int i = 0;
	while (s[i] == ' ') {
		i += 1;
	}
	while (s[s.length() - 1] == ' ') {
		s.pop_back();
	}
	int n = 0;
	bool isNeg = false;
	for (i; i < s.length(); ++i) {
		char c = s[i];
		if (c >= '0' && c <= '9') {
			n = n * 10 + (c - '0');
		} else if (c == '-') {
			isNeg = true;
		} else {
			if (isNeg) {
				n *= -1;
			}
			result.push_back(n);
			n = 0;
			isNeg = false;
		}
	}
	if (isNeg) {
		n *= -1;
	}
	result.push_back(n);
	return result;
}

Graph buildGraph(ifstream& in) {
	vector<edge> e;
	int v;
	if (in.is_open()) {
		string line;
		while (getline(in, line)) {
			vector<int> nums = extractIntTokens(line);
			if (nums.size() == 1) {
				v = nums[0];
			} else {
				e.push_back(edge(nums[0], nums[1], nums[2]));
			}
		}
	}
	return Graph(v, e);
}

int main(int argc, char *argv[]) {
	if (argc < 2) {
		cout << "Please specify input file" << endl;
		return 0;
	}
	ifstream in(argv[1]);
	Graph g = buildGraph(in);

	int start = 0;
	g.dijkstra(start);
	cout << "The shortest paths costs starting from node: " << start << endl;
	for (int i = 0; i < g.getVertices().size(); ++i) {
		printf("%4d", i);
	}
	cout << endl;
	for (vertex v : g.getVertices()) {
		printf("%4d", v.val);
	}
	cout << endl;

	int dest = 1 + rand() % (g.getVertexCount() - 1);
	cout << "Shorted Path from " << start << " to " << dest << " is: " << endl;
	vector<int> path = g.getPath(start, dest);
	for (int i = 0; i < path.size(); ++i) {
		cout << path[i];
		if (path[i] != dest) {
			cout << " -> ";
		}
	}
	cout << endl;

	cout << "Press enter to exit" << endl;
	string s;
	getline(cin, s);
	return 0;
}