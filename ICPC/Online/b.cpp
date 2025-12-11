//
// b.cpp
// Created by Wasif on 11/23/25 at 11:27:41.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.rbegin(), a.rend());
    int m;
    cin >> m;
    if(n > m) {
        a.resize(m);
        n = m;
    }
    vector<int> dp(1 << n, 1e9);
    vector<array<int, 2>> opt(m);
    for(int i = 0; i < m; i++) {
        char p;
        string s;
        cin >> p >> s;
        opt[i] = {p == 'A', s == "pick"};
    }
    auto f = [&] (int mask, auto&& self) -> int {
        int k = __builtin_popcount(mask);
        if(k == m) return 0;
        if(dp[mask] != 1e9) return dp[mask];

        int player = opt[k][0], pick = opt[k][1];
        int ans = (player ? -1e9 : 1e9);
        for(int i = 0; i < n; i++) {
            if((1 << i) & mask) continue;
            int next = self(mask | (1 << i), self);
            if(pick) {
                if(player) ans = max(ans, a[i] + next);
                else ans = min(ans, -a[i] + next);
            } else {
                if(player) ans = max(ans, next);
                else ans = min(ans, next);
            }
        }
        return dp[mask] = ans;
    };

    int diff = f(0, f);
    if(diff > 0) cout << "A ";
    else cout << "B ";
    cout << diff << '\n';
}