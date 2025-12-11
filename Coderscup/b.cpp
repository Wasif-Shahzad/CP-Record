//
// b.cpp
// Created by Wasif on 11/20/25 at 11:20:48.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define all(x) x.begin(), x.end()

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for(int i = 0; i <= 60; i++) {
        if((1ll << i) >= n) {
            cout << (1ll << i) << '\n';
            return 0;
        }
    }
}