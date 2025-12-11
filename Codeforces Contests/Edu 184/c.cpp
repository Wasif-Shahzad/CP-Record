//
// c.cpp
// Created by Wasif on 11/14/25 at 19:24:31.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    vector<int> pref(n + 1, 0), suff(n + 2, 0);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    suff[n] = a[n];
    for(int i = n - 1; i > 0; i--) {
        suff[i] = suff[i + 1] + a[i];
    }
    int ans = pref[n];
    set<int> s;
    map<int, int> ind;
    ans = max(ans, pref[n - 1] + 2 * n);
    ind[*s.begin()] = n;
    s.insert(n * n + n - pref[n]);
    for(int i = n - 1; i > 0; i--) {
        int our = i * i - i - pref[i - 1];
        int val = i * i + i - pref[i];
        s.insert(val);
        ind[val] = i;
        if(*s.rbegin() > our) {
            int gain = *s.rbegin() - our;
            int r = ind[*s.rbegin()];
            ans = max(ans, pref[i - 1] + suff[r + 1] + pref[r] - pref[i - 1] + gain);
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solve();
}