//
// b.cpp
// Created by wasifshahzad on 12/31/25 at 19:35:06.
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
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int mn = a[0], mx = a[0];
        for(int i = 1; i < n; i++) {
            mn += 2 * a[i];
        }
        int nxt = a[n - 1], cur = 0;
        for(int i = n - 2; i > 0; i--) {
            nxt = a[i] + 2 * nxt;
        }
        mx += 2 * nxt;
        cout << mn << " " << mx << '\n';
    }
}