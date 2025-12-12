//
// Brute.cpp
// Created by Wasif on 12/12/25 at 11:50:17.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = n + 2;
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            for(int x = i; x <= j; x++) {
                for(int y = x; y <= j; y++) {
                    if((a[x] ^ a[y]) >= k) {
                        ans = min(ans, j - i + 1);
                    }
                }
            }
        }
    }
    cout << (ans > n ? -1 : ans) << '\n';
}