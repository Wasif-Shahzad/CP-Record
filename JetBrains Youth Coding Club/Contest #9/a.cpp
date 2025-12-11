//
// a.cpp
// Created by Wasif on 12/09/25 at 07:20:38.
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
    sort(a.rbegin(), a.rend());
    int take = 0, sum = accumulate(a.begin(), a.end(), 0ll);
    for(int i = 0; i < n; i++) {
        sum -= a[i];
        take += a[i];
        if(take > sum) {
            cout << i + 1 << '\n';
            break;
        }
    }
}