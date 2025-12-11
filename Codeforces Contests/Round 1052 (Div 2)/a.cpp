//
// a.cpp
// Created by Wasif on 12/08/25 at 20:36:39.
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
        int n;
        cin >> n;
        map<int, int> f1;
        map<int, int, greater<int>> f2;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            f1[x]++;
        }
        for(auto [v, c]: f1) {
            f2[c]++;
        }
        int ans = 0, big = 0;
        for(auto [v, c]: f2) {
            ans = max(ans, c * v + big * v);
            big += c;
        }
        cout << ans << '\n';
    }
}