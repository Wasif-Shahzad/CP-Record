//
// c.cpp
// Created by wasifshahzad on 04/12/26 at 12:06:16.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

void solve() {
    int n, k, p, q;
    cin >> n >> k >> p >> q;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int ans = 1e16;
    auto get = [&] (int l, int r, int op) -> int {
        int here = 0;
        for(int i = l; i <= r; i++) {
            if(op == 1) here += a[i] % p % q;
            else if(op == 2) here += a[i] % q % p;
            else if(op == 3) here += a[i] % p;
            else if(op == 4) here += a[i] % q;
            else here += a[i] % p % q;
        }
        return here;
    };
    vector<vector<int>> pref(7, vector<int>(n + 1, 0));
    for(int j = 1; j <= 5; j++) {
        for(int i = 1; i <= n; i++) {
            pref[j][i] = pref[j][i - 1] + get(i, i, j);
        }
    }
    for(int i = 1; i <= n; i++) {
        pref[6][i] = pref[6][i - 1];
        int bst = 1e16;
        for(int j = 1; j <= 5; j++) {
            bst = min(bst, pref[j][i] - pref[j][i - 1]);
        }
        pref[6][i] += bst;
    }
    int tot = pref[6][n];
    for(int i = k; i <= n; i++) {
        int l = i - k; 
        int here = tot - pref[6][i] + pref[6][l];
        int bst = 1e16;
        for(int j = 1; j <= 5; j++) {
            bst = min(bst, pref[j][i] - pref[j][l]);
        }
        here += bst;
        ans = min(ans, here);
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