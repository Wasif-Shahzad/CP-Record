//
// d.cpp
// Created by Wasif on 11/21/25 at 21:09:00.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    map<pair<string, int>, int> cnt;
    for(int i = 0; i < n; i++) {
        string tmp, good;
        cin >> tmp;
        for(auto i: tmp) {
            if(i != '-') good += i;
        }
        for(int j = 0; j < 12; j++) {
            string here;
            for(int k = 0; k < 12; k++) {
                if(k == j) continue;
                here += good[k];
            }
            cnt[{here, j}]++;
        }
    }
    int ans = 0;
    for(auto [s, t]: cnt) {
        ans += t * (t - 1) / 2;
    }
    cout << ans << '\n';
}