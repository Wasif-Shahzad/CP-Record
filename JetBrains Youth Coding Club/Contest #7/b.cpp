//
// b.cpp
// Created by Wasif on 11/24/25 at 08:17:29.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;
    int l = a + 1, r = b;
    r = min(r, l + (int)1e8);
    int ans = 1;
    for(int i = l; i <= r; i++) {
        ans = (ans * (i % 10)) % 10;
    }
    cout << ans % 10 << '\n';
}