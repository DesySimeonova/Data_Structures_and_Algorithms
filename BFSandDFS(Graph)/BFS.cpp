#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
using namespace std;

const int N = 1000000;
bool visited[N]{ false };
unordered_map<int, vector<int>> graph;

void bfs(int edge) {
	list<int> queue;
	queue.push_back(edge);
	visited[edge] = true;
	while (!queue.empty()) {
		edge = queue.front();
		queue.pop_front();
		//searching condition
		for (int i : graph[edge]) {
			if (!visited[edge]) {
				visited[edge] = true;
				queue.push_back(edge);
			}
		}
	}

}
