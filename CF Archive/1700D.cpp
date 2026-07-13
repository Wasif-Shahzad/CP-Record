//
// 1700D.cpp
// Created by wasifshahzad on 06/16/26 at 18:23:16.
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
    vector<int> a(n + 1, 0);
    vector<int> pref(n + 1, 0);
    int sm = 0;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        sm += a[i];
        pref[i] = pref[i - 1] + a[i];
    }
    auto f = [&] (int x) -> bool {
        for(int i = 1; i <= n; i++) {
            if((pref[i] + x - 1) / x > i) return false;
        }
        return true;
    };
    int lo = 0, hi = 1e13;
    while(hi > lo + 1) {
        int mid = (hi + lo) / 2;
        if(f(mid)) hi = mid;
        else lo = mid;
    }
    int q;
    cin >> q;
    while(q--) {
        int t;
        cin >> t;
        if(t < hi) {
            cout << -1 << ' ';
        } else {
            cout << (sm + t - 1) / t << ' ';
        }
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