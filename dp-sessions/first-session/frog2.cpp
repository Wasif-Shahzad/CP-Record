//
// frog2.cpp
// Created by wasifshahzad on 02/10/26 at 20:58:29.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

int n, k;
vector<int> a, storage;

int f(int i) {
    if(i == n) return 0;
    if(storage[i] != -1) return storage[i];
    int bst = 1e10;
    for(int j = 1; j <= k; j++) {
        int ni = i + j;
        if(ni > n) continue;
        bst = min(bst, abs(a[i] - a[ni]) + f(ni));
    }
    return storage[i] = bst;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    a.resize(n + 1, 0);
    storage.resize(n + 1, -1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    cout << f(1) << '\n';
}