//
// a.cpp
// Created by Wasif on 09/20/25 at 16:59:27.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c;
    cin >> a >> b >> c;
    if(a == b || a == c || b == c) cout << "Yes\n";
    else cout << "No\n";
}