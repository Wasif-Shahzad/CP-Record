//
// c.cpp
// Created by wasifshahzad on 01/01/26 at 21:52:47.
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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int &i: a) cin >> i;
        int sm = accumulate(a.begin(), a.end(), 0ll);
        if(k >= n) {
            int ans = 0;
            for(int i = k - 1; i >= k - n + 1; i--) ans += i;
            ans += sm;
            ans += k - n;
            cout << ans << '\n';
        } else {
            vector<int> pref(n, 0);
            pref[0] = a[0];
            for(int i = 1; i < n; i++) {
                pref[i] = pref[i - 1] + a[i];
            } 
            int ans = k * (k - 1) / 2;
            int bst = 0;
            for(int i = k - 1; i < n; i++) {
                int here = pref[i] - (i - k >= 0 ? pref[i - k] : 0);
                bst = max(bst, here);
            }
            ans += bst;
            cout << ans << '\n';
        }
    }
}