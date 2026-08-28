#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<int> a(k);
    for(int i = 0; i < k; i++) {
        cin >> a[i];
        a[i]--;
    }
    int b = 0;
    vector<vector<int>> g(n);
    for(int i = 0; i < n; i++) {
        int t;
        cin >> t;
        for(int j = 0; j < t; j++) {
            int v;
            cin >> v;
            if(v == i + 1) {
                b = 1;
            }
            g[v - 1].push_back(i);
        }
    }
    if(b) {
        cout << -1 << '\n';
        return 0;
    }
    vector<int> order, vis(n, 0);
    auto build = [&] (int v, auto&& self) -> void {
        vis[v] = 1;
        for(int c: g[v]) {
            if(vis[c]) continue;
            self(c, self);
        }
        order.push_back(v);
    };
    for(int i = 0; i < n; i++) {
        if(!vis[i]) {
            build(i, build);
        }
    }
    reverse(order.begin(), order.end());
    vector<int> id(n);
    for(int i = 0; i < n; i++) {
        id[order[i]] = i;
    }
    vector<int> dp(n, 0);
    for(int i = 0; i < k; i++) {
        dp[a[i]] = 1;
    }
    for(int i = n - 1; i >= 0; i--) {
        int v = order[i];
        for(int c: g[v]) {
            dp[v] += dp[c];
        }
    }
    vector<int> ans, have(n, 0);
    for(int i = 0; i < n; i++) {
        if(dp[order[i]]) ans.push_back(order[i]), have[order[i]] = 1;
    }
    for(int i: ans) {
        for(int c: g[i]) {
            if(id[c] < id[i]) b = 1;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int c: g[i]) {
            if(!have[i] && have[c]) {
                b = 1;
                break;
            }
        }
    }
    if(b) {
        cout << -1 << '\n';
        return 0;
    }
    cout << ans.size() << '\n';
    for(int v: ans) cout << v + 1 << ' ';
    cout << '\n';
}
