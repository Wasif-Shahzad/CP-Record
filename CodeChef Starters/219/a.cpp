//
// a.cpp
// Created by wasifshahzad on 12/31/25 at 19:28:50.
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
        int n;
        cin >> n;
        string s;
        cin >> s;
        int x = 0, y = 0, ans = 0;
        for(auto i: s) {
            if(i == '0') y++;
            else x++;
            ans += x >= y;
        }
        cout << ans << '\n';
    }
}