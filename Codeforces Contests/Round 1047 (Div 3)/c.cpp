//
// c.cpp
// Created by wasifshahzad on 9/7/25 at 19:32:41.
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
        int a, b;
        cin >> a >> b;
        int k = b;
        if(b & 1) {
            if(a & 1) {
                int ans = k * a + 1;
                cout << ans << '\n';
            } else {
                cout << -1 << '\n';
            }
        } else {
            if(a & 1) {
                // need even divisor such that b / k is even
                if(b / 2 & 1) {
                    cout << -1 << '\n';
                } else {
                    k = b / 2;
                    int ans = k * a + b / k;
                    cout << ans << '\n';
                }
            } else {
                // need a divisor such that b / k is even
                k = b / 2;
                int ans = k * a + b / k;
                cout << ans << '\n';
            }
        }
    }
}