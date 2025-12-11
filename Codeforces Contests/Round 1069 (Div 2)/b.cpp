//
// b.cpp
// Created by Wasif on 12/06/25 at 13:10:57.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> pref(n + 1, 0);
        iota(pref.begin(), pref.end(), 0);
        pref[r] = pref[l - 1];
        vector<int> a(n);
        for(int i = 1; i <= n; i++) {
            a[i - 1] = pref[i] ^ pref[i - 1];
        }
        for(int i = 0; i < n; i++) cout << a[i] << " ";
        cout << '\n';
    }
}