// Arrays.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    int N, M;
    cin >> N >> M;
    int temp;
    vector<int> x;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        x.push_back(temp);
    }
    sort(x.begin(), x.end());
    for (int i = 0; i < M; i++) {
        cin >> temp;
        vector<int>::iterator lower_bound_iter = lower_bound(x.begin(), x.end(), temp);
        cout << lower_bound_iter - x.begin() << " ";
    }

    return 0;
}

