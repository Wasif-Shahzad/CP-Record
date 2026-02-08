//
// a.cpp
// Created by wasifshahzad on 01/01/26 at 18:39:44.
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
    // gcd(x + d, y + d)
    // gcd(y + d, x - y)
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int &i: a) cin >> i;
        sort(a.begin(), a.end());
        cout << a[n - 1] - a[0] <<"\n";
    }
}