//
// a.cpp
// Created by wasifshahzad on 01/01/26 at 21:01:08.
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
        int n, h;
        cin >> n >> h;
        vector<int> a(n);
        for(int &i: a) cin >> i;
        sort(a.rbegin(), a.rend());
        int tot = h / (a[0] + a[1]);
        h -= tot * (a[0] + a[1]);
        int mv = tot * 2;
        if(h > 0) {
            h -= a[0];
            mv++;
        }
        if(h > 0) {
            h -= a[1];
            mv++;
        }
        cout << mv << '\n';
    }
}