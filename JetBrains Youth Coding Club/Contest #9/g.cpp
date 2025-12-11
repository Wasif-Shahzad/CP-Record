//
// g.cpp
// Created by Wasif on 12/09/25 at 09:14:15.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    int mx = 0;
    vector<int> a(n);
    vector<int> boundaries;
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
        mx = max(mx, a[i]);
        boundaries.push_back(1);
        for(int l = 1, r; l <= a[i]; l = r + 1) {
            int v = (a[i] + l - 1) / l;
            if(v == 1) {
                r = a[i];
            } else {
                int tmp = (a[i] - 1) / (v - 1);
                r = tmp;
            }
            boundaries.push_back(r + 1);
        }
    }
    int S = sum + k;
    sort(boundaries.begin(), boundaries.end());
    boundaries.erase(unique(boundaries.begin(), boundaries.end()), boundaries.end());

    int ans = 0;
    for(int i = 0; i + 1 < boundaries.size(); i++) {
        int l = boundaries[i];
        int r = boundaries[i + 1] - 1;
        int csum = 0;
        for(int j = 0; j < n; j++) {
            csum += (a[j] + l - 1) / l;
        }
        int d = S / csum;
        d = min(d, r);
        if(d >= l) {
            ans = max(ans, d);
        }
    }

    int d = S / n;
    if(d >= mx) ans = max(ans, d);
    cout << ans << '\n';
}