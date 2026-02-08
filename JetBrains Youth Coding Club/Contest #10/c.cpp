//
// c.cpp
// Created by wasifshahzad on 12/16/25 at 07:18:49.
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
    int n;
    cin >> n;
    while(n--) {
        int x; cin >> x;
        int ans = 0;
        if(x == 2) {
            cout << -1 << '\n';
            continue;
        }
        if(x == 1 || x == 3 || x == 5 || x == 7 || x == 11) {
            cout << -1 << '\n';
            continue;
        }
        if(x & 1) {
            ans = 1;
            x -= 9;
        }
        ans += x / 4;
        cout << ans << '\n';
    }
}