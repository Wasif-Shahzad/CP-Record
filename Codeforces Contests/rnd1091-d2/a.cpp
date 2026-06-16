//
// a.cpp
// Created by wasifshahzad on 04/07/26 at 19:31:23.
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
    vector<int> a(n);
    int s = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        s += a[i];
    }
    if(s & 1) {
        cout << "YES\n";
        return;
    }
    if(k * n % 2 == 0) {
        cout << "YES\n";
        return;
    }
    cout << "NO\n";
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