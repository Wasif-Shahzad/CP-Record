//
// a.cpp
// Created by Wasif on 09/20/25 at 19:21:35.
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
        int x, y;
        cin >> x >> y;
        if(y > x) cout << 2 << '\n';
        else {
            if(y >= 2 && x > y + 1) cout << 3 << '\n';
            else cout << -1 << '\n';
        }
    }
}