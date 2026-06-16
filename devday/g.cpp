//
// g.cpp
// Created by wasifshahzad on 04/30/26 at 13:22:51.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

void solve() {
    int n;
    cin >> n;
    int ans = 0;
    int tmp = n;
    while(tmp > 0) {
        if(tmp % 10 == 0) {
            tmp /= 10;
            continue;
        }
        if(n % (tmp % 10) == 0) ans++;
        tmp /= 10;
    }
    cout << ans << '\n';
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