//
// code2.cpp
// Created by Wasif on 10/31/25 at 20:55:44.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

void normalize(pair<int, int> &frac) {
    int g = __gcd(frac.first, frac.second);
    frac.first /= g;
    frac.second /= g;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    pair<int, int> cur = {0, 0};
    map<pair<int, int>, int> cnt;
    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'D') cur.first++;
        else cur.second++;
        if(cur.first == 0 || cur.second == 0) {
            cout << max(cur.first, cur.second) << " ";
        } else {
            auto tmp = cur;
            normalize(tmp);
            cnt[tmp]++;
            ans = max(ans, cnt[tmp]);
            cout << ans << " ";
        }
    }
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