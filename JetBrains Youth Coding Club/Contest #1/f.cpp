//
// f.cpp
// Created by Wasif on 10/05/25 at 14:58:51.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(m);
    for(int i = 0; i < m; i++) {
        int x; cin >> x;
        x = min(x, n / 2);
        a[i] = {x, i};
    }
    sort(a.rbegin(), a.rend());
    vector<int> ans(n, -1);
    int i = 0, j = 1, k = 0;
    while(i < n && k < m) {
        auto [v, y] = a[k];
        while(i < n && v > 0) {
            ans[i] = y;
            i += 2;
            v--;
        }
        if(v == 0) k++;
        else a[k].first = v;
    }
    while(j < n && k < m) {
        auto [v, y] = a[k];
        while(j < n && v > 0) {
            ans[j] = y;
            j += 2;
            v--;
        }
        if(v == 0) k++;
        else a[k].first = v;
    }
    if(count(ans.begin(), ans.end(), -1) > 0) {
        cout << -1 << '\n';
    } else {
        for(int i = 0; i < n; i++) {
            cout << ans[i] + 1 << " \n"[i + 1 == n];
        }
    }
}