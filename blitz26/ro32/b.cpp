//
// b.cpp
// Created by wasifshahzad on 03/13/26 at 23:25:12.
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
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(all(a)); reverse(all(a));
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += i * a[i].first + 1;
    }
    cout << ans << '\n';
    for(int i = 0; i < n; i++) {
        cout << a[i].second + 1 << " \n"[i + 1 == n];
    }
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