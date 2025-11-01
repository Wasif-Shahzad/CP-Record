//
// a.cpp
// Created by Wasif on 10/06/25 at 19:16:55.
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
        int n;
        cin >> n;
        if(n % 3 == 0) cout << 0 << '\n';
        else cout << 3 - n % 3 << '\n';
    }
}