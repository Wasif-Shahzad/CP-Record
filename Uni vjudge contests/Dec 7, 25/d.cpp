//
// d.cpp
// Created by Wasif on 12/07/25 at 21:31:28.
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
        int a, b, x;
        cin >> a >> b >> x;
        bool good = false;
        if(a > b) swap(a, b);
        while(true) {
            if(a == x || b == x) {
                good = true;
                break;
            }
            if(a == 0) {
                break;
            }
            // b - k * a = x
            // b - x = k * a
            // (b - x) / k
            if(a <= x && x <= b) {
                int diff = b - x;
                if(diff % a) {
                    break;
                }
                good = true;
                break;
            }
            int tmp = a;
            a = b % a;
            b = tmp;
        }
        cout << (good ? "YES" : "NO") << '\n';
    }
}