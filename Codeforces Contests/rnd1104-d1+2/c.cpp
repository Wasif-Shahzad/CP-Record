//
// c.cpp
// Created by wasifshahzad on 06/18/26 at 20:03:39.
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
    vector<int> a(n);
    for(int &i: a) cin >> i;
    int cur = a[0];
    for(int i = 1; i < n; i++) {
        if(a[i] < cur) {
            cur += a[i];
        } else {
            cur = a[i];
        }
    }
    cout << cur << '\n';
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