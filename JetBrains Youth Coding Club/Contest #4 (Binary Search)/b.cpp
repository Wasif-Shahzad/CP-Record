//
// b.cpp
// Created by Wasif on 10/29/25 at 14:27:33.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int k;
        cin >> k;
        auto f = [&] (int x) -> bool{
            int terms = sqrtl(x);
            return x - terms >= k;
        };
        int lo = 0, hi = 1;
        while(!f(hi)) hi *= 2;
        while(hi > lo + 1) {
            int mid = (hi + lo) / 2;
            if(f(mid)) hi = mid;
            else lo = mid;
        }
        cout << hi << '\n';
    }
}