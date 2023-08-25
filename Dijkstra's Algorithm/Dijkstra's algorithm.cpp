#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>
using namespace std;
unordered_map<int, vector<pair<int,int>>> graph;

const int N = 100000;
int distTo[N];

void Dijkstra(int edge) {
    for (int i = 0; i < N; i++) distTo[i] = INT_MAX;
    distTo[edge] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0,edge });
    while (!pq.empty()) {
        int current = pq.top().second;
        int distToCurr = pq.top().first;
        pq.pop();
        for (pair<int, int> neighbour : graph[current]) {
            int child = neighbour.second;
            int distToChild = neighbour.first;
            if (distTo[child] > distToChild + distToCurr) {
                distTo[child] = distToChild + distToCurr;
                pq.push({ distToChild + distToCurr,child });
            }
        }
    }
}

int main()
{
    int K;//num of edges
    cin >> K;
    int V;//num of vertices
    cin >> V;
    int temp1, temp2, dist;
    for (int i = 0; i < V; i++) {
        cin >> temp1 >> temp2 >> dist;
        graph[temp1].push_back({ dist,temp2 });
        graph[temp2].push_back({ dist,temp1 });

    }
    Dijkstra(0);
    for (int i = 0; i < K; i++) {
        cout << "From 0 to " << i << " the dist is " << distTo[i] << '\n';
    }
}

