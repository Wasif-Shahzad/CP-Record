//
// 1272E.cpp
// Created by wasifshahzad on 04/15/26 at 15:09:59.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

const int N = 2e5+5;
int n;
vector<vector<int>> g(N);

vector<int> bfs(vector<int> st) {
    vector<int> vis(n, 0), d(n, 1e9);
    queue<int> q;
    for(int i = 0; i < n; i++) {
        if(st[i]) {
            d[i] = 0;
            vis[i] = 1;
            q.push(i);
        }
    }
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(int c: g[v]) {
            if(vis[c]) continue;
            d[c] = d[v] + 1;
            q.push(c);
            vis[c] = 1;
        }
    }
    return d;
}

void solve() {
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(i - a[i] + 1 > 0) {
            g[i - a[i]].push_back(i);
        }
        if(i + a[i] < n) {
            g[i + a[i]].push_back(i);
        }
    }
    vector<int> ans(n, -1);
    vector<int> st(n, 0);
    for(int i = 0; i < n; i++) {
        if(a[i] & 1) st[i] = 1;
    }
    vector<int> cur = bfs(st);
    for(int i = 0; i < n; i++) {
        if((a[i] & 1)^1) ans[i] = (cur[i] <= n ? cur[i] : -1);
    }
    for(int i = 0; i < n; i++) st[i] ^= 1;
    cur = bfs(st);
    for(int i = 0; i < n; i++) {
        if(a[i] & 1) ans[i] = (cur[i] <= n ? cur[i] : -1);
    }
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i + 1 == n];
    }
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