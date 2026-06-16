//
// 1205B.cpp
// Created by wasifshahzad on 05/11/26 at 12:48:34.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

void solve() {
    // max cycle length is 60 by pigeonhole
    // edge exists if both have a common bit
    // x (common bit) y (common bit) z (common bit) x
    // if n > 120 then atleast one bit has 3 occurences so answer is 3
    // throw away the numbers which are powers of 2
    // we can create the graph now
    int n;
    cin >> n;
    vector<int> tmp(n);
    for(int &i: tmp) cin >> i;
    vector<int> a;
    for(int i = 0; i < n; i++) {
        if(tmp[i] != 0) a.push_back(tmp[i]);
    }
    n = a.size();
    if(n > 120) {
        cout << 3 << '\n';
        return;
    }
    vector<vector<int>> g(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            if((a[i] & a[j]) > 0) {
                g[i].push_back(j);
            }
        }
    }
    int ans = 500;
    vector<int> vis(n, 0), par(n, -1), dis(n, 200);
    auto calc = [&] (int v) -> void {
        vis.assign(n, 0);
        par.assign(n, -1);
        dis.assign(n, 200);
        queue<int> q;
        vis[v] = 1;
        dis[v] = 0;
        q.push(v);
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int c: g[u]) {
                if(c == par[u]) continue;
                if(dis[c] == 200) {
                    dis[c] = dis[u] + 1;
                    vis[c] = 1;
                    q.push(c);
                    par[c] = u;
                    continue;
                }
                ans = min(ans, dis[c] + dis[u] + 1);
            }
        }
    };
    for(int i = 0; i < n; i++) {
        calc(i);
    }
    cout << (ans == 500 ? -1 : ans) << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}