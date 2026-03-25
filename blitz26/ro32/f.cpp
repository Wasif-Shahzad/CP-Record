//
// f.cpp
// Created by wasifshahzad on 03/14/26 at 00:02:59.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<pair<int, int>> pref(n);
    int cur = 0;
    for(int i = 0; i < n; i++) {
        pref[i] = {cur, i};
        cur += (s[i] == '(' ? 1 : -1);
    }
    sort(all(pref), [&] (auto x, auto y) {
        if(x.first != y.first) return x.first < y.first;
        return x.second > y.second;
    });
    for(int i = 0; i < n; i++) {
        cout << s[pref[i].second];
    }
    cout << '\n';
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