//
// a.cpp
// Created by wasifshahzad on 8/23/25 at 14:16:18.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> ind(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ind[a[i]] = i;
    }
    int q;
    cin >> q;
    while (q--) {
        int x, y;
        cin >> x >> y;
        swap(ind[x], ind[y]);
    }
    vector<int> ans(n);
    for (int i = 1; i <= n; i++) {
        ans[ind[i]] = i;
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';
}