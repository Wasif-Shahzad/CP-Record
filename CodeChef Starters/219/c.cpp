//
// c.cpp
// Created by wasifshahzad on 12/31/25 at 19:40:35.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        if(n == 2) {
            cout << -1 << '\n';
            continue;
        }
        if(n == 3) {
            cout << "1 1 1\n0 1 1\n0 1 1\n";
            continue;
        }
        if(n == 4) {
            cout << "1 1 1 1\n0 0 1 1\n0 0 1 1\n0 0 0 1\n";
            continue;
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0 || j == 0 || i == n - 1 || j == n - 1 || j == n - 3) {
                    cout << 1 << " ";
                } else cout << 0 << " ";
            }
            cout << '\n';
        }
    }
}