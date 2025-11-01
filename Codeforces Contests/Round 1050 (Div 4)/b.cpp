//
// b.cpp
// Created by Wasif on 09/13/25 at 20:47:02.
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
        int n, m, x, y;
        cin >> n >> m >> x >> y;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
        }
        for(int i = 0; i < m; i++) {
            int x; cin >> x;
        }
        cout << n + m << '\n';
    }
}