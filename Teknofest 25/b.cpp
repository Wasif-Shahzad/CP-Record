//
// b.cpp
// Created by wasifshahzad on 01/03/26 at 12:52:28.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

int dp[101];

void solve() {
    int n;
    cin >> n;
    cout << (dp[n] ? "First" : "Second") << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    dp[1] = 0;
    dp[0] = 0;
    for(int i = 2; i <= 100; i++) {
        for(int j: {2, 3, 5}) {
            if(i - j < 0) break;
            if(!dp[i - j]) {
                dp[i] = 1;
                break;
            }
        }
    }
    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }
}