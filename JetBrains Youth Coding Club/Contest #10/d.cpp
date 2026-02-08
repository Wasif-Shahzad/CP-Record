//
// d.cpp
// Created by wasifshahzad on 12/16/25 at 07:45:43.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

bool isGood(int x, int p) {
    int mn = x + 1;
    for(int i = 1; i * i <= x; i++) {
        if(x % i == 0) {
            if(i != 1) mn = min(mn, i);
            if(mn <= p) return false;
            if(x / i != 1) mn = min(mn, x / i);
            if(mn <= p) return false;
        }
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int p, y;
    cin >> p >> y;
    bool f = false;
    for(int i = y; i > max(p, i - 1000); i--) {
        if(isGood(i, p)) {
            cout << i << '\n';
            f = true;
            break;
        }
    }
    if(!f) cout << -1 << '\n';
}