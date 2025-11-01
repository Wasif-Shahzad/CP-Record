//
// h.cpp
// Created by Wasif on 10/09/25 at 20:28:19.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> g(2 * n);
    vector<array<int, 2>> input(n);
    for(int i = 0; i < n; i++) {
        cin >> input[i][0] >> input[i][1];
        input[i][0]--, input[i][1]--;
        g[input[i][0]].push_back(input[i][1]);
        g[input[i][1]].push_back(input[i][0]);
    }
    for(int i = 0; i < 2 * n; i += 2) {
        int j = (i + 1) % (2 * n);
        g[i].push_back(j);
        g[j].push_back(i);
        j = (((i - 1) % (2 * n)) + (2 * n)) % (2 * n);
        g[i].push_back(j);
        g[j].push_back(i);
    }
    vector<int> color(2 * n), vis(2 * n, 0);
    auto dfs = [&] (int v, int c, auto&& self) -> void{
        color[v] = c;
        vis[v] = 1;
        for(int ch: g[v]) {
            if(vis[ch]) continue;
            self(ch, !c, self);
        }
    };
    for(int i = 0; i < 2 * n; i++) {
        if(!vis[i]) {
            dfs(i, 0, dfs);
        }
    }
    for(auto [u, v]: input) {
        cout << color[u] + 1 << " " << color[v] + 1 << '\n';
    }
}