//
// a.cpp
// Created by wasifshahzad on 9/7/25 at 19:31:44.
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
        int k, x;
        cin >> k >> x;
        cout << x * (1ll << k) << '\n';
    }
}