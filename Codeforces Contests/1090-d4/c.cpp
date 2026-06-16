//
// c.cpp
// Created by wasifshahzad on 04/05/26 at 10:56:24.
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
    vector<int> ans(3 * n, -1);
    vector<int> rem(3 * n);
    iota(all(rem), 1);
    for(int i = 1; i < 3 * n; i += 3) {
        ans[i] = rem.back();
        rem.pop_back();
        ans[i + 1] = rem.back();
        rem.pop_back();
    }
    for(int i = 0; i < 3 * n; i += 3) {
        ans[i] = rem.back();
        rem.pop_back();
    }
    for(int i = 0; i < 3 * n; i++) cout << ans[i] << " ";
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