//
// f.cpp
// Created by Wasif on 11/24/25 at 10:22:47.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y;
    cin >> x >> y;
    int a = y, b = y, c = y;
    int ops = 0;
    while(a != x || b != x || c != x) {
        if(a > b) swap(a, b);
        if(b > c) swap(b, c);
        if(a > b) swap(a, b);
        a = min(x, b + c - 1);
        ops++;
    }   
    cout << ops << '\n';
}