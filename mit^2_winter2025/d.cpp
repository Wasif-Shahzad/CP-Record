//
// d.cpp
// Created by Wasif on 12/07/25 at 23:08:29.
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
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector<int> suff(n);
        suff[n - 1] = a[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            suff[i] = __gcd(a[i], suff[i + 1]);
        }
        int l = a[0];
        if(suff[1] % l == 0) {
            cout << l << '\n';
            continue;
        }
        bool good = false;
        for(int i = 1; i + 1 < n; i++) {
            l = lcm(l, a[i]);
            if(suff[i + 1] % l == 0) {
                good = true;
                break;
            }
            if(l > suff[i + 1]) break;
        }
        if(good) cout << l << '\n';
        else cout << -1 << '\n';
    }
}