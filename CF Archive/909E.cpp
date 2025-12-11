//
// 909E.cpp
// Created by Wasif on 11/30/25 at 21:09:27.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> rev(n);
    vector<int> out(n, 0), e(n);
    for(int i = 0; i < n; i++) {
        cin >> e[i];
    }
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        rev[v].push_back(u);
        out[u]++;
    }
    vector<int> cur, vis(n, 0);
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(!out[i]) {
            cur.push_back(i);
            vis[i] = 1;
        }
    }
    while(!cur.empty()) {
        bool need = false;
        queue<int> q;
        vector<int> nxt;
        for(int v: cur) {
            if(e[v]) {
                q.push(v);
                need = true;
            } else {
                for(int c: rev[v]) {
                    if(vis[c]) continue;
                    out[c]--;
                    vis[c] = 1;
                    if(out[c] == 0 && e[c] == 1) {
                        q.push(c);
                        need = true;
                    } else {
                        nxt.push_back(c);
                    }
                }
            }
        }
        if(need) ans++;
        while(!q.empty()) {
            int v = q.front();
            q.pop();
            vis[v] = 1;
            for(int c: rev[v]) {
                if(out[c] > 1) {
                    out[c]--;
                    continue;
                }
                out[c] = 0;
                if(e[c] == 1) {
                    q.push(c);
                } else {
                    nxt.push_back(c);
                }
            }
        }
        cur.swap(nxt);
    }
    cout << ans << '\n';
}