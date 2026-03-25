//
// 1117C.cpp
// Created by wasifshahzad on 03/24/26 at 17:14:33.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

void solve() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int n;
    cin >> n;
    string s;
    cin >> s;
    int tx = 0, ty = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'U') ty++;
        else if(s[i] == 'D') ty--;
        else if(s[i] == 'L') tx--;
        else tx++;
    }
    auto f = [&] (int k) -> bool {
        int sx = k / n * tx, sy = k / n * ty;
        int rem = k % n;
        for(int i = 0; i < rem; i++) {
            if(s[i] == 'U') sy++;
            else if(s[i] == 'D') sy--;
            else if(s[i] == 'L') sx--;
            else sx++;
        }
        int cx = x1 + sx, cy = y1 + sy;
        int dist = abs(cx - x2) + abs(cy - y2);
        return dist <= k;
    };
    int lo = 0, hi = 1;
    while(hi <= 8e18 / 2 && !f(hi)) hi *= 2;
    if(!f(hi)) {
        cout << -1 << '\n';
        return;
    }
    while(hi > lo + 1) {
        int mid = (hi + lo) / 2;
        if(f(mid)) hi = mid;
        else lo = mid;
    }
    cout << hi << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}