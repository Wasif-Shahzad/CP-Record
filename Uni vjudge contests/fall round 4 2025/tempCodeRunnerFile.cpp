//
// main.cpp
// Created by Wasif on 09/19/25 at 21:25:26.
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
    if(x > 0 && y > 0) cout << 1 << '\n';
    else if(x < 0 && y > 0) cout << 2 << '\n';
    else if(x < 0 && y < 0) cout << 3 << '\n';
    else cout << 4 << '\n';
}