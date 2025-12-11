//
// 2026D.cpp
// Created by Wasif on 12/08/25 at 16:51:28.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

/*
let f[i] = s(i, i + 1) + s(i, i + 2) ... + s(i, n)
let suff[i] = f[i] + suff[i + 1]
first compute l1 and l2 such that 
*/

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
}