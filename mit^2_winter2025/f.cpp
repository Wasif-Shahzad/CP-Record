//
// f.cpp
// Created by Wasif on 12/08/25 at 00:51:45.
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
        int x, y, z;
        cin >> x >> y >> z;
        int n = x + y + z;
        if(max({x, y, z}) > n / 2) {
            cout << "No\n";
            continue;
        }
        
    }
}