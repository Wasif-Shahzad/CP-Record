//
// 1307D.cpp
// Created by wasifshahzad on 06/12/26 at 10:00:07.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(k), sp(n, 0);
    for(int i = 0; i < k; i++) {
        cin >> a[i];
        a[i]--;
        sp[a[i]] = 1;
    }
    bool fl = false;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        if(sp[u] && sp[v]) {
            fl = true;
        }
        g[u].push_back(v);
        g[v].push_back(u);
    }
    const int oo = 1e11;
    vector<int> dist(n, oo), dist2(n, oo);
    dist[0] = 0;
    queue<int> q;
    q.push(0);
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(int c: g[v]) {
            if(dist[v] + 1 < dist[c]) {
                dist[c] = dist[v] + 1;
                q.push(c);
            }
        }
    }
    dist2[n - 1] = 0;
    q.push(n - 1);
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(int c: g[v]) {
            if(dist2[v] + 1 < dist2[c]) {
                dist2[c] = dist2[v] + 1;
                q.push(c);
            }
        }
    }
    if(fl) {
        cout << dist[n - 1] << '\n';
        return;
    }
    sort(all(a), [&dist] (int x, int y) {
        return dist[x] < dist[y];
    });
    int cur = dist2[a[k - 1]];
    int bst = 0;
    for(int i = k - 2; i >= 0; i--) {
        bst = max(bst, dist[a[i]] + 1 + cur);
        cur = max(cur, dist2[a[i]]);
    }
    sort(all(a), [&dist2] (int x, int y) {
        return dist2[x] > dist2[y];
    });
    cur = dist[a[0]];
    for(int i = 1; i < k; i++) {
        bst = max(bst, cur + 1 + dist2[a[i]]);
        cur = max(cur, dist[a[i]]);
    }
    cout << min(bst, dist[n - 1]) << '\n';
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