#include <cmath>
#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;


int main() {
    int K, T, B;
    cin >> K >> T >> B;
    int N;
    cin >> N;
    queue<int>buff;
    priority_queue<int, vector<int>, greater<int>> queries;
    int temp;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        buff.push(temp);
    }
    int time = 0;
    for (int i = 0; i < B; i++) {
        time += T;
        for (int i = 0; i < T; i++) {
            if (!buff.empty()) {
                queries.push(buff.front());
                buff.pop();
            }
        }
        for (int i = 0; i < K; i++) {
            if (!queries.empty()) {
                cout << queries.top() << " ";
                queries.pop();
            }
        }
    }

    return 0;
}