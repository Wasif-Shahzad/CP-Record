//
// 412D.cpp
// Created by wasifshahzad on 9/1/25 at 18:43:30.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int N = 3e4;
bitset<N> mat[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        mat[u].set(v);
    }
    vector<int> order{0};
    for (int i = 1; i < n; i++) {
        int j = order.size() - 1;
        order.push_back(i);
        while (j >= 0) {
            int u = order[j], v = order[j + 1];
            if (mat[u].test(v)) swap(order[j], order[j + 1]);
            else break;
            j--;
        }
    }
    for (int v: order) cout << v + 1 << " ";
    cout << '\n';
}