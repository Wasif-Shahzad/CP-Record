#include <bits/stdc++.h>
#include <queue>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    vector<int> deg(n, 0);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        deg[u]++, deg[v]++;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int MAX = *max_element(deg.begin(), deg.end());
    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<array<int, 2>>> pq;
    vector<int> ans(n + 1), isRemoved(n, 0);
    for(int i = 0; i < n; i++) {
        pq.push({deg[i], i});
    }
    int cur_k = 0;
    while (!pq.empty()) {
        auto [d, v] = pq.top();
        pq.pop();
        if (isRemoved[v]) continue;
        ans[v] = max(cur_k, d);
        for(int c: g[v]) {
            if (isRemoved[c]) continue;
            deg[c]--;
            pq.push({deg[c], c});
        }
        isRemoved[v] = 1;
        cur_k = max(cur_k, d);
    }
    vector<int> pref(MAX + 1, 0);
    for(int i = 0; i < n; i++) {
        pref[ans[i]]++;
    }
    for(int i = 1; i <= MAX; i++) pref[i] += pref[i - 1];
    int q;
    cin >> q;
    while (q--) {
        int k;
        cin >> k;
        if (k > MAX) cout << 0 << '\n';
        else if(k == 0) cout << n << '\n';
        else cout << n - pref[k - 1] << '\n';
    }
}
