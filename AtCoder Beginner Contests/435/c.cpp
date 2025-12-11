//
// c.cpp
// Created by Wasif on 12/06/25 at 17:14:47.
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
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int j = a[0];
    for(int i = 1; i < n; i++) {
        if(i + 1 <= j) {
            j = max(j, i + a[i]);
        } else break;
    }
    cout << min(n, j) << '\n';
}