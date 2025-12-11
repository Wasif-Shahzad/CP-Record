//
// c.cpp
// Created by Wasif on 11/20/25 at 11:20:44.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define all(x) x.begin(), x.end()

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n, m, s;
        cin >> n >> m >> s;
        int rem = n - s + 1;
        if(rem >= m) {
            cout << s + m - 1 << '\n';
            continue;
        }
        m -= rem;
        int target = m % n;
        if(target == 0) cout << n << '\n';
        else cout << target << '\n';
    }
}