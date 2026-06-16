//
// a.cpp
// Created by wasifshahzad on 04/12/26 at 10:43:34.
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
    vector<int> a(k);
    vector<pair<int, int>> b(n);
    for(int i = 0; i < k; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i].first;
        b[i].second = i;
    }
    sort(b.rbegin(), b.rend());
    vector<int> res;
    for(auto [v, i]: b) {
        for(int j = v; j < k + 1; j++) {
            res.push_back(i);
        }
    }
    cout << res.size() << '\n';
    for(int i: res) cout << i + 1 << " ";
    cout << '\n';
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