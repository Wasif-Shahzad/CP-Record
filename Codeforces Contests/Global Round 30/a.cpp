//
// a.cpp
// Created by Wasif on 11/06/25 at 19:34:02.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int x;
    cin >> x;
    for(int i = 0; i + 1 < n; i++) {
        if(min(a[i], a[i + 1]) <= x && max(a[i], a[i + 1]) >= x) {
            cout << "YES\n";
            return;
        }
    }
    if(n == 1) cout << (a[0] == x ? "YES" : "NO") << '\n';
    else cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while(T--) {
        solve();
    }
}