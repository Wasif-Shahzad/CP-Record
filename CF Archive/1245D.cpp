//
// 1245D.cpp
// Created by Wasif on 11/29/25 at 10:27:28.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

/*
for cities at same coordinates, build for one optimally only 
if ci <= ki build a tower there
pre-compute the cost for having a wire with all others
graph + MST?
*/

struct Edge {
    int w = 1e15, to = -1;
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> coord(n);
    vector<int> c(n), k(n);
    for(int i = 0; i < n; i++) {
        cin >> coord[i].first >> coord[i].second;
    }
    for(int i = 0; i < n; i++) {
        cin >> c[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> k[i];
    }

    vector<vector<int>> adj(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int dist = abs(coord[i].first - coord[j].first) + abs(coord[i].second - coord[j].second);
            adj[i][j] = dist * (k[i] + k[j]);
        }
    }

    vector<int> vis(n, 0);
    vector<Edge> min_e(n);
    int cost = 0;
    vector<pair<int, int>> edges;
    vector<int> pre;
    for(int i = 0; i < n; i++) {
        min_e[i].w = c[i];
    }

    for(int i = 0; i < n; i++) {
        int v = -1;
        for(int j = 0; j < n; j++) {
            if(!vis[j] && (v == -1 || min_e[j].w < min_e[v].w)) {
                v = j;
            }
        }

        vis[v] = 1;
        cost += min_e[v].w;

        if(min_e[v].to != -1) {
            edges.push_back({v, min_e[v].to});
        } else {
            pre.push_back(v);
        }

        for(int to = 0; to < n; to++) {
            if(adj[v][to] < min_e[to].w) {
                min_e[to].w = adj[v][to];
                min_e[to].to = v;
            }
        }
    }    

    cout << cost << '\n';
    cout << pre.size() << '\n';
    for(int i: pre) cout << i + 1 << " ";
    cout << '\n';
    cout << edges.size() << '\n';
    for(auto [u, v]: edges) {
        cout << u + 1 << " " << v + 1 << '\n';
    }
}