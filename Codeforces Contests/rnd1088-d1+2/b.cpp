//
// b.cpp
// Created by wasifshahzad on 03/28/26 at 20:02:17.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

int facts(int x) {
    if(x == 0) return 1;
    int res = 0;
    for(int i = 1; i * i <= x; i++) {
        if(x % i == 0) {
            res++;
            if(x / i != i) res++;
        }
    }
    return res;
}

void solve() {
    int x, y;
    cin >> x >> y;
    cout << facts(abs(x - y)) << '\n';
    for(int i = 0; i < x; i++) cout << 1 << " ";
    for(int i = 0; i < y; i++) cout << -1 << " ";
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