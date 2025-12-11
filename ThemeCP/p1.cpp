//
// p1.cpp
// Created by Wasif on 11/30/25 at 14:34:25.
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
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if(n == 1) {
            cout << 1 << '\n';
            continue;
        }
        sort(a.rbegin(), a.rend());
        int g = 0;
        for(int i = 1; i < n; i++) {
            g = __gcd(g, a[0] - a[i]);
        }
        int ops = 0, pl = 0;
        for(int i = 1; i < n; i++) {
            if(a[i - 1] - a[i] > g && !pl) {
                pl = 1;
                int x = a[i - 1] - g;
                ops += (a[0] - x) / g;
            }
            ops += (a[0] - a[i]) / g;
        }
        if(!pl) {
            ops += n;
        }
        cout << ops << '\n';
    }
}