//
// a.cpp
// Created by Wasif on 11/24/25 at 08:09:35.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> b(n, 0);
    b[0] = a[0];
    int x = 0;
    for(int i = 1; i < n; i++) {
        int have = b[i - 1] + a[i];
        int rem = max(0ll, k - have);
        x += rem;
        b[i] = a[i] + rem;
    }
    cout << x << '\n';
    for(int i = 0; i < n; i++) {
        cout << b[i] << " ";
    }
    cout << '\n';
}