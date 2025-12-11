//
// b.cpp
// Created by Wasif on 11/28/25 at 19:31:15.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

void solve() {
    int n;
    cin >> n;
    vector<int> b(n);
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    sort(b.rbegin(), b.rend());
    int m = n - count(b.begin(), b.end(), 0);
    int s = accumulate(b.begin(), b.end(), 0ll);
    int ans = min(m, s - (n - 1));
    ans = max(ans, 0ll);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solve();
}