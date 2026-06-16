//
// c.cpp
// Created by wasifshahzad on 04/30/26 at 19:43:15.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

// 2 3 2 3
// [1, 2], [1, 4], [2, 3], [3, 4], [1, 3], [2, 4]

void solve() {
    int n;
    cin >> n;
    vector<int> a, b, c, d, e;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if(x % 6 == 0) {
            b.push_back(x);
        } else if(x % 2 == 0) {
            c.push_back(x);
        } else if(x % 3 == 0) {
            d.push_back(x);
        } else {
            e.push_back(x);
        }
    }
    for(int i: b) cout << i << " ";
    for(int i: c) cout << i << " ";
    for(int i: e) cout << i << " ";
    for(int i: d) cout << i << " ";
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