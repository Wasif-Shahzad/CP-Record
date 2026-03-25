//
// d.cpp
// Created by wasifshahzad on 03/13/26 at 23:49:44.
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
    string s;
    cin >> s;
    map<string, int> mp;
    for(int i = 0; i + 1 < n; i++) {
        string cur = string(1, s[i]);
        cur += s[i + 1];
        mp[cur]++;
    }
    int cur = 0;
    string ans;
    for(auto [v, c]: mp) {
        if(c > cur) {
            cur = c;
            ans = v;
        }
    }
    cout << ans << '\n';
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