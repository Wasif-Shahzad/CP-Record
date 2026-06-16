//
// 1656D.cpp
// Created by wasifshahzad on 05/07/26 at 15:18:09.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

void solve() {
    // for odd numbers, k = 2 works
    // for n mod 4 = 2, k = 4 works and n > 2
    // (n - k * (k + 1) / 2) mod k = 0
    // for even k, 2 * n mod k = 0
    int n;
    cin >> n;
    int x = 2 * n;
    for(int i = 1; i <= 31; i++) {
        if(x % (1ll << i) == 0 && n % (1ll << i) != 0) {
            int k = (1ll << i);
            if(k * (k + 1) / 2 <= n) {
                cout << k << '\n';
                return;
            }
        }
    }
    while(x % 2 == 0) x >>= 1;
    if(x != 1 && x <= 5e9 && x * (x + 1) / 2 <= n) {
        cout << x << '\n';
    } else {
        cout << -1 << '\n';
    }
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