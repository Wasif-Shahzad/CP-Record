//
// 1204C.cpp
// Created by Wasif on 10/22/25 at 12:22:20.
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
    vector<vector<int>> dist(n, vector<int>(n, 1e9));
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        dist[i][i] = 0;
        for(int j = 0; j < n; j++) {
            if(s[j] == '1') dist[i][j] = 1;
        }
    }
    for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int m;
    cin >> m;
    vector<int> p(m);
    for(int i = 0; i < m; i++) {
        cin >> p[i];
        p[i]--;
    }
    vector<int> ans;
    for(int i = 0; i + 1 < m; ) {
        ans.push_back(p[i]);
        int our = p[i];
        int j = i + 1;
        for(; j < m; j++) {
            if(dist[our][p[j]] == j - i) continue;
            break;
        }
        i = j - 1;
    }
    ans.push_back(p[m - 1]);
    cout << ans.size() << '\n';
    for(int v: ans) cout << v + 1 << " ";
    cout << '\n';
}