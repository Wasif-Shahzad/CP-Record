//
// a.cpp
// Created by wasifshahzad on 12/19/25 at 19:29:47.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int l, a, b;
        cin >> l >> a >> b;
        vector<int> vis(l, 0);
        vis[a] = 1;
        int ans = a;
        int j = a;
        while(true) {
            vis[j] = 1;
            j = (j + b) % l;
            if(vis[j]) break;
            ans = max(ans, j);
        }
        cout << ans << '\n';
    }
}