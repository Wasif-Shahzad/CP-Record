//
// a.cpp
// Created by Wasif on 10/11/25 at 16:51:21.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0; i < n / 2; i++) cout << s[i];
    for(int i = n / 2 + 1; i < n; i++) cout << s[i];
}