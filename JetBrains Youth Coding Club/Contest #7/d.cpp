//
// d.cpp
// Created by Wasif on 11/24/25 at 08:36:45.
//

#include <bits/stdc++.h>
using namespace std;
// #define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int d, s;
    cin >> d >> s;
    vector<pair<int, int>> a(d);
    for(int i = 0; i < d; i++) {
        cin >> a[i].first >> a[i].second;
    }
    vector<vector<int>> dp(d + 1, vector<int>(s + 1, 0));
    dp[d][0] = 1;
    for(int i = d - 1; i >= 0; i--) {
        for(int x = a[i].first; x <= a[i].second; x++) {
            for(int j= 0; j <= s; j++) {
                if(j - x >= 0) {
                    dp[i][j] = max(dp[i][j], dp[i + 1][j - x]);
                }
            }
        }
    }
    if(!dp[0][s]) {
        cout << "NO\n";
        return 0;
    }
    int rem = s;
    vector<int> have;
    for(int i = 0; i < d; i++) {
        for(int x = a[i].first; x <= a[i].second; x++) {
            if(rem - x >= 0) {
                if(dp[i][rem] && dp[i + 1][rem - x]) {
                    have.push_back(x);
                    rem -= x;
                    break;
                }
            }
        }
    }
    cout << "YES\n";
    for(int i: have) cout << i << " ";
}