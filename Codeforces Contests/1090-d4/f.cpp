//
// f.cpp
// Created by wasifshahzad on 04/05/26 at 11:33:44.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

/*
always have lesser than or equal to 4 levels of depth
odd can't be 0
even = 0, just make a clique
even <= odd always
*/

void solve() {
    int x, y;
    cin >> x >> y;
    if(x > y) {
        cout << "NO\n";
        return;
    }
    if(y == 0) {
        cout << "NO\n";
        return;
    }
    if(x == 0) {
        if(y % 2 == 0) {
            cout << "NO\n";
            return;
        }
        cout << "YES\n";
        for(int i = 2; i <= x + y; i++) {
            cout << 1 << " " << i << '\n';
        }
        return;
    }
    int lim = ((x + y) & 1 ? 2 * x + 1 : 2 * x);
    vector<pair<int, int>> e;
    for(int i = 2; i <= lim; i++) e.push_back({i - 1, i});
    int rem = (x + y) - lim;
    for(int i = lim + 1; i <= lim + rem; i++) {
        e.push_back({1, i});
    }
    cout << "YES\n";
    assert((int)e.size() == x + y - 1);
    for(auto [u, v]: e) cout << u << " " << v << '\n';
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