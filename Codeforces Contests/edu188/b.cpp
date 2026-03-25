//
// b.cpp
// Created by wasifshahzad on 03/16/26 at 19:39:09.
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
    for(int i = 0; i < n; i++) cin >> a[i];
    vector<pair<int, int>> bst(n);
    bst[0] = {a[0], 0};
    for(int i = 1; i < n; i++) {
        if(a[i] > bst[i - 1].first) {
            bst[i] = {a[i], i};
        } else if(a[i] == bst[i - 1].first) {
            bst[i] = {a[i], i};
        } else {
            bst[i] = bst[i - 1];
        }
    }
    int j = n - 1;
    int ans = 0;
    while(j >= 0) {
        auto [x, i] = bst[j];
        ans++;
        j = i - 1;
    }
    cout << ans << '\n';
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