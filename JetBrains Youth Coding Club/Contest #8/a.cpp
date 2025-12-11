//
// a.cpp
// Created by Wasif on 12/02/25 at 09:25:17.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    int ans = 0;
    while(n > 0) {
        if(n >= m) {
            ans += m;
            n -= m;
            n++;
        } else {
            ans += n;
            break;
        }
    }
    cout << ans << '\n';
}