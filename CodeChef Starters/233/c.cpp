//
// c.cpp
// Created by wasifshahzad on 04/08/26 at 19:39:53.
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
    vector<int> a(n), b(n), c(n);
    vector<pair<int, int>> d;
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i] >> c[i];
        d.push_back({a[i], i});
        d.push_back({b[i], i});
        d.push_back({c[i], i});
    }
    sort(all(d));
    map<int, int> ind;
    int ans = 1e10;
    int l = 0;
    // for(int i = 0; i < 3 * n; i++) {
    //     cout << "(" << d[i].first << ", " << d[i].second << "), ";
    // }
    // cout << '\n';
    for(int r = 0; r < 3 * n; r++) {
        ind[d[r].second]++;
        while(l + 1 < r && (int)ind.size() == n) {
            if(ind[d[l].second] == 1) break;
            ind[d[l].second]--;
            l++;
        }
        if((int)ind.size() == n) {
            ans = min(ans, d[r].first - d[l].first);
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