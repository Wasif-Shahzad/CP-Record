//
// A.cpp
// Created by wasifshahzad on 8/24/25 at 20:16:33.
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
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> cnt(101, 0);
        int mx = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
            mx = max(mx, cnt[a[i]]);
        }
        cout << (mx >= 2 ? "YES" : "NO") << '\n';
    }
}