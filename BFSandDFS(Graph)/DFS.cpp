#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

const int N = 1000000;
bool visited[N]{ false };
unordered_map<int, vector<int>> graph;

void dfs(int edge) {
	visited[edge] = true;
	//searching condition
	for (int i : graph[edge]) {
		if (!visited[i]) {
			dfs(i);
		}
	}
}
