//
// d.cpp
// Created by wasifshahzad on 8/20/25 at 20:53:40.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

map<int, int> c0, c1;

int f0(int x) {
    if (c0.count(x)) return c0[x];
    if (x == 0) return 0;
    int cur = 1;
    while (cur * 2 <= x) cur *= 2;
    return c0[x] = cur + f0(cur - 1) + f0(x - cur);
}

int f1(int x) {
    if (c1.count(x)) return c1[x];
    if (x == 1) return 0;
    int cur = 1;
    while (cur * 2 <= x) cur *= 2;
    return c1[x] = cur + (cur == x) + f1(cur - 1) + f0(x - cur);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        cout << f1(n) << '\n';
    }
}