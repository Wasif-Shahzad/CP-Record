//
// a.cpp
// Created by wasifshahzad on 06/18/26 at 19:33:48.
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
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    int r = n;
    while(r > 0) {
        int i = min_element(a.begin(), a.begin() + r) - a.begin();
        ans += (r - i) * a[i];
        r = i;
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