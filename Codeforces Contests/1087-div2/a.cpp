//
// a.cpp
// Created by wasifshahzad on 03/22/26 at 12:38:28.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

void solve() {
    int n, c, k;
    cin >> n >> c >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(all(a));
    int ans = c;
    for(int i = 0; i < n; i++) {
        if(a[i] <= ans) {
            if(k > 0) {
                int ch = min(ans - a[i], k);
                a[i] += ch;
                k -= ch;
            }
            ans += a[i];
        }
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