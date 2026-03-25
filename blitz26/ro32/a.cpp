//
// a.cpp
// Created by wasifshahzad on 03/13/26 at 23:08:21.
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
    int cnt = 0;
    for(int &i: a) {
        cin >> i;
        cnt += (i & 1);
    }
    cout << (cnt % 2 == 0 ? "YES" : "NO") << '\n';
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