#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int, map<int, int>> graph;
vector<int> edges;


int main() {
    int M, N;
    cin >> N >> M;
    int x, y, z;
    for (int i = 0; i < M; i++) {
        cin >> x >> y >> z;
        graph[x][y] = z;
        graph[y][x] = z;
    }
    int K;
    cin >> K;
    for (int i = 0; i < K; i++) {
        cin >> x;
        edges.push_back(x);
    }
    int result = 0;
    bool isValidPath = true;
    for (int i = 0; i < K - 1; i++) {
        if (graph[edges[i]].find(edges[i + 1]) == graph[edges[i]].end()) {
            isValidPath = false;
            break;
        }
        else {
            result += graph[edges[i]][edges[i + 1]];
        }
    }
    if (!isValidPath)
        cout << -1;
    else
        cout << result;

    return 0;
}