//
// d.cpp
// Created by wasifshahzad on 8/28/25 at 20:53:57.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int ask(char dir, int k) {
    cout << "? " << dir << " " << k << endl;
    int d;
    cin >> d;
    return d;
}

void ans(int x, int y) {
    cout << "! " << x << " " << y << endl;
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        pair<int, int> mx = {-1e10, -1e10}, mn = {1e10, 1e10};
        int mx_sum = -2e10, mn_sum = -2e10;
        for (int i = 0; i < n; i++) {
            int x, y;
            cin >> x >> y;
            if (x + y > mx_sum) {
                mx_sum = x + y;
                mx = {x, y};
            }
            if (x - y > mn_sum) {
                mn_sum = x - y;
                mn = {x, y};
            }
        }
        ask('U', 1e9);
        ask('U', 1e9);
        ask('R', 1e9);
        int d1 = ask('R', 1e9);
        int c1 = d1 + mx.first + mx.second - 4e9;
        ask('D', 1e9);
        ask('D', 1e9);
        ask('D', 1e9);
        int d2 = ask('D', 1e9);
        int c2 = d2 + mn.first - mn.second - 4e9;
        int x = (c1 + c2) / 2;
        int y = c1 - x;
        ans(x, y);
    }
}