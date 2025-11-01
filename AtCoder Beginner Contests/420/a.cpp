//
// a.cpp
// Created by wasifshahzad on 8/26/25 at 09:05:48.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int x, y;
    cin >> x >> y;
    int ans = (x + y) % 12;
    if (ans == 0) ans = 12;
    cout << ans << '\n';
}