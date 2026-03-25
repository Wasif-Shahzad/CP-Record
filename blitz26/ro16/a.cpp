//
// a.cpp
// Created by wasifshahzad on 03/15/26 at 15:18:19.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> ans;
    for(int i = 1; i <= n; i += 2) {
        int r = (i + k) * (i + 1);
        if(r % 4 == 0) {
            ans.push_back({i, i + 1});
            continue;
        }
        r = (i + 1 + k) * i;
        if(r % 4 == 0) {
            ans.push_back({i + 1, i});
            continue;
        }
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for(auto [u, v]: ans) {
        cout << u << " " << v << '\n';
    }
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