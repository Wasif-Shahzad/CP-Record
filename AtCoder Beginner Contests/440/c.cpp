//
// c.cpp
// Created by wasifshahzad on 01/10/26 at 16:57:21.
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
        int n, w;
        cin >> n >> w;
        vector<int> a(n);
        vector<int> mp(2 * w, 0);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            mp[(i + 1) % (2 * w)] += a[i];
        }
        int ans = 0;
        for(int i = 0; i < w; i++) {
            ans += mp[i];
        }
        int cur = ans;
        for(int i = w; i < 2 * w; i++) {
            cur -= mp[i - w];
            cur += mp[i];
            ans = min(ans, cur);
        }
        cout << ans << '\n';
    }
}