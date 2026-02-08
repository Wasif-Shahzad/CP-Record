//
// a.cpp
// Created by wasifshahzad on 12/16/25 at 07:18:45.
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
    int n, m;
    cin >> n >> m;
    int mn1 = 10, mn2 = 10;
    vector<int> has(10, 0);
    int com = -1;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        mn1 = min(mn1, x);
        has[x] = 1;
    }
    for(int i = 0; i < m; i++) {
        int x; cin >> x;
        mn2 = min(mn2, x);
        if(has[x]) {
            if(com == -1) com = x;
            else com = min(com, x);
        }
    }
    if(com != -1) cout << com << '\n';
    else cout << min(mn1, mn2) << max(mn1, mn2) << '\n';
}