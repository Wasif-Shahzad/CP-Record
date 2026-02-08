//
// b.cpp
// Created by wasifshahzad on 01/10/26 at 16:57:18.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++) {
        a[i].second = i;
        cin >> a[i].first;
    }
    sort(a.begin(), a.end());
    for(int i = 0; i < 3; i++) cout << a[i].second + 1 << " ";
}