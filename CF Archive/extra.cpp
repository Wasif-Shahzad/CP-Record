//
// extra.cpp
// Created by Wasif on 10/20/25 at 21:22:19.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> a = {1, 3, 3, 7};
    int ans = 0;
    for(int i = 1; i < 15; i++) {
        int mx = 0;
        for(int j = 0; j < 4; j++) {
            if((1 << j) & i) {
                mx = max(mx, a[j]);
            }
        }
        ans += mx;
    }
    cout << ans << '\n';
}