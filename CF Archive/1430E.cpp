//
// 1430E.cpp
// Created by wasifshahzad on 05/25/26 at 20:03:16.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

// bgwebe => ebewgb
// ebgwbe (3)
// ebgwbe (3)
// ebegwb (6)
// ebewgb (7)

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string t = s;
    reverse(all(t));
    vector<int> ptr(26, 0), add(26, 0);
    vector<vector<int>> ind(26), rm(26, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        ind[s[i] - 'a'].push_back(i);
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        add[t[i] - 'a'] -= rm[t[i] - 'a'][ptr[t[i] - 'a']];
        int j = ind[t[i] - 'a'][ptr[t[i] - 'a']];
        ans += j - i + add[t[i] - 'a'];
        ptr[t[i] - 'a']++;
        for(int k = 0; k < 26; k++) {
            if(k == t[i] - 'a') continue;
            int y = upper_bound(ind[k].begin() + ptr[k], ind[k].end(), j) - ind[k].begin();
            if(y != (int)ind[k].size()) rm[k][y]++;
            add[k]++;
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