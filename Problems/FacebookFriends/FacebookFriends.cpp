

#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

unordered_map<int, vector<int>> facebook;
const int N = 10000000;
bool visited[N];
int groups = 0;

void dfs(int v, int& size ) {
    visited[v] = true;

    for (auto i : facebook[v]) {
        if (!visited[i]) {
            size++;
            dfs(i, size);
        }
    }
}


int main() {
    int N, E, K;
    cin >> N >> E >> K;
    int k, j;
    for (int i = 0; i < E; i++)
    {
        cin >> k >> j;
        facebook[k].push_back(j);
        facebook[j].push_back(k);
    }
    for (int i = 0; i < N; i++)
    {
        if (!visited[i]) {
            int size = 1;
            dfs(i,size);
            if (size % K == 0)
                groups++;
        }
    }

    cout << groups;
    return 0;
}

