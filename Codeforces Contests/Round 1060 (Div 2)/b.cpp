//
// b.cpp
// Created by Wasif on 10/19/25 at 20:12:56.
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
        int mx = a[0];
        for(int i = 1; i < n; i++) {
            mx = max(mx, a[i]);
            if(i % 2 == 1) {
                if(a[i] < a[i - 1] || (i + 1 < n && a[i] < a[i + 1]))
                    a[i] = mx;
            }
        }
        mx = a[0];
        int ans = 0;
        for(int i = 1; i < n; i++) {
            if(i & 1) {
                if(a[i] > a[i - 1]) {
                    a[i] = max(a[i], mx);
                } else {
                    a[i] = mx;
                    if(a[i - 1] == mx) ans++;
                }
            } else {
                if(a[i] >= a[i - 1]) {
                    ans += a[i] - mx + 1;
                    a[i] = mx - 1;
                }
            }
            mx = max(mx, a[i]);
        }
        cout << ans << '\n';
    }
}