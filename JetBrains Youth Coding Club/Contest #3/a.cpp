//
// a.cpp
// Created by Wasif on 10/19/25 at 09:33:05.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int x = -1, y = -1;
    for(int i = 0; i < n; i++) {
        int j; cin >> j;
        if(j == 1) x = i;
        else if(j == n) y = i;
    }
    cout << max({x, y, n - x - 1, n - y - 1}) << '\n';
}