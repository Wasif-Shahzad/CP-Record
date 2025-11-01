//
// b.cpp
// Created by Wasif on 10/10/25 at 19:25:13.
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
        int x, y, z;
        cin >> x >> y >> z;
        int a = x | z, b = x | y, c = y | z;
        if((a & b) == x && (b & c) == y && (a & c) == z) cout << "YES\n";
        else cout << "NO\n";
    }
}