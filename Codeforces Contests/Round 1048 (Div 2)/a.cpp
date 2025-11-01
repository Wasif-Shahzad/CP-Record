//
// a.cpp
// Created by Wasif on 09/08/25 at 19:16:28.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int a, b;
        cin >> a >> b;
        int x = lcm(a, b);
        if(x == a && x == b) cout << 0 << '\n';
        else if(x == a || x == b) cout << 1 << '\n';
        else cout << 2 << '\n';
    }   
}