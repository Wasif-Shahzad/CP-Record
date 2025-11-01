//
// a.cpp
// Created by wasifshahzad on 8/28/25 at 19:32:27.
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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        c -= a, d -= b;
        if (b > a) swap(a, b);
        if (c > d) swap(c, d);
        if (b < (a - 1) / 2) {
            cout << "NO\n";
            continue;
        }
        if (c < (d - 1) / 2) {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }
}