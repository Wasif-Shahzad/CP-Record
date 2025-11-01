//
// C.cpp
// Created by wasifshahzad on 8/21/25 at 21:24:37.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> cost(31), get(31);
    for (int i = 0; i <= 30; i++) {
        int x = pow(3, i);
        get[i] = x;
        if (i != 0) cost[i] = x * 3 + i * x / 3;
        else cost[i] = 3;
    }
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int ans = 0;
        for (int i = 30; i >= 0; i--) {
            while (get[i] <= n) {
                n -= get[i];
                ans += cost[i];
            }
        }
        cout << ans << '\n';
    }
}