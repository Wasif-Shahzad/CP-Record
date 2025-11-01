//
// a.cpp
// Created by Wasif on 10/25/25 at 17:04:05.
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
    for(int i = 1; i <= n; i++) {
        if(i <= m) cout << "OK\n";
        else cout << "Too Many Requests\n";
    }
}