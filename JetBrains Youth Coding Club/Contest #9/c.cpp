//
// c.cpp
// Created by Wasif on 12/09/25 at 07:34:34.
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
    map<int, int> freq;
    vector<vector<int>> loc(1e6 + 1);
    int mx = 0;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        freq[x]++;
        mx = max(mx, freq[x]);
        loc[x].push_back(i);
    }
    int len = n + 5, l = -1, r = -1;
    for(auto [v, c]: freq) {
        if(c == mx) {
            int i = loc[v][0], j = loc[v].back();
            if(j - i + 1 < len) {
                len = j - i + 1;
                l = i, r = j;
            }
        }
    }
    cout << l + 1 << " " << r + 1 << '\n';
}