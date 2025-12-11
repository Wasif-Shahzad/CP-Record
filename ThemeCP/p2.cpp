//
// p2.cpp
// Created by Wasif on 11/30/25 at 14:47:20.
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
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        int x = -1, y = -1;
        for(int i = a + 1; i <= c; i++) {
            if(a * b % i == 0) {
                int tmp = a * b / i;
                // multiple of l in [b + 1, d]
                int l = (b + tmp) / tmp;
                int r = d / tmp;
            }
        }
    }
}