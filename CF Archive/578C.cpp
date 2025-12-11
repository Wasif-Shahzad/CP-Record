//
// 578C.cpp
// Created by Wasif on 12/03/25 at 07:38:02.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    auto f = [&] (long double x) -> long double {
        vector<long double> b(n);
        for(int i = 0; i < n; i++) {
            b[i] = a[i] - x;
        }
        long double mx = max(b[0], 0.0L), mn = min(0.0L, b[0]), ans = abs(b[0]), cur = b[0];
        for(int i = 1; i < n; i++) {
            cur += b[i];
            mx = max(mx, cur);
            mn = min(mn, cur);
            if(cur > 0) {
                ans = max(ans, cur - mn);
            } else {
                ans = max({ans, abs(cur - mx), abs(cur)});
            }
        }
        return ans;
    };

    long double lo = -1e12, hi = 1e12;
    for(int i = 0; i < 150; i++) {
        long double m1 = lo + (hi - lo) / 2, m2 = hi - (hi - lo) / 3;
        if(f(m1) > f(m2)) lo = m1;
        else hi = m2;
    }

    cout << setprecision(6) << fixed << f(lo) << '\n';
}