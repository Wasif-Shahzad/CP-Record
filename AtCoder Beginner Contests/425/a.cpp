//
// a.cpp
// Created by Wasif on 09/30/25 at 10:12:53.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int ans = 0;
    int n;
    cin >> n;
    for(int i = 1; i<= n; i++) {
        if(i & 1) ans += -(i * i * i);
        else ans += i * i * i;
    }
    cout << ans;
}