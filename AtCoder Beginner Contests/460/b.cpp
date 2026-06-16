//
// b.cpp
// Created by wasifshahzad on 05/30/26 at 17:01:13.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

// 

void solve() {
    int x1, y1, r1, x2, y2, r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    int dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
    cout << (((r1 - r2) * (r1 - r2) <= dist) and (dist <= (r1 + r2) * (r1 + r2)) ? "Yes" : "No") << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}