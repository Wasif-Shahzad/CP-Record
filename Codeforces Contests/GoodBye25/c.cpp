//
// c.cpp
// Created by wasifshahzad on 12/27/25 at 19:29:15.
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
        vector<int> a(n + 1), pref(n + 1, 0), neg(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            pref[i] = pref[i - 1] + abs(a[i]);
            neg[i] = neg[i - 1] - a[i];
        }
        int ans = 0;
        for(int i = 2; i <= n; i++) ans -= a[i];
        for(int i = 2; i <= n; i++) {
            int here = a[1] + pref[i - 1] - pref[1];
            here += neg[n] - neg[i];
            ans = max(ans, here);
        }
        cout << ans << '\n';    
    }
}