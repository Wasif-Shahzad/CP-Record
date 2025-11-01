//
// g.cpp
// Created by Wasif on 09/25/25 at 20:10:48.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        int n, q;
        cin >> n >> q;
        vector<int> a(n);
        vector<vector<int>> loc(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        auto b = a;
        sort(b.begin(), b.end());
        vector<int> val(n), c(n);
        for(int i = 0; i < n; i++) {
            c[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
            val[c[i]] = a[i];
            loc[c[i]].push_back(i);
        }
        while(q--) {
            int l, r;
            cin >> l >> r;
            l--, r--;
            int x = -1, y = -1;
            for(int k = 1; k <= 50; k++) {
                int i = l + (rng() % (r - l + 1));
                int elem = c[i];
                int f = upper_bound(loc[elem].begin(), loc[elem].end(), r) - lower_bound(loc[elem].begin(), loc[elem].end(), l);
                if(f > (r - l + 1) / 3) {
                    if(elem == x || elem == y) continue;
                    if(x == -1) x = elem;
                    else if(y == -1) y = elem;
                }
                if(x != -1 && y != -1) break;
            }
            if(x == -1 && y == -1) cout << -1 << '\n';
            else {
                if(x > y) swap(x, y);
                if(x == -1 || y == -1) {
                    cout << val[y] << '\n';
                } else {
                    cout << val[x] << " " << val[y] << '\n';
                }
            }
        }
    }
}