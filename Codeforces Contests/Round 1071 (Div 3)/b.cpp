//
// b.cpp
// Created by wasifshahzad on 12/23/25 at 19:33:22.
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
        vector<int> a(n + 1);
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }   
        vector<int> pref(n + 2, 0), suff(n + 2, 0);
        for(int i = 2; i <= n; i++) {
            pref[i] = pref[i - 1] + abs(a[i] - a[i - 1]);
        }
        for(int i = n - 1; i > 0; i--) {
            suff[i] = suff[i + 1] + abs(a[i] - a[i + 1]);
        }
        int ans = pref[n];
        for(int i = 1; i <= n; i++) {
            int l = pref[i - 1], r = suff[i + 1];
            int here = l + r;
            if(i + 1 <= n && i - 1 > 0) here += abs(a[i + 1] - a[i - 1]);
            ans = min(ans, here);
        }
        cout << ans << '\n';
    }
}