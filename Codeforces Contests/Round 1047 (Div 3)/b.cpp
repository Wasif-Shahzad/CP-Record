//
// b.cpp
// Created by wasifshahzad on 9/7/25 at 19:31:56.
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
        vector<int> a(n), b(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            b[i] = n + 1 - a[i];
        }
        for(int i = 0; i < n; i++) {
            cout << b[i] << " \n"[i + 1 == n];
        }
    }
}