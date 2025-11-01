//
// c.cpp
// Created by Wasif on 10/19/25 at 09:33:13.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, x;
    cin >> n >> x;
    pair<int, int> cur = {x, n % 2};
    auto orig = cur;
    vector<int> pos = {x};
    while(true) {
        int m = cur.second;
        if(m == 0) {
            if(cur.first == 1) cur.first = 2;
            else if(cur.first == 2) cur.first = 1;
        } else {
            if(cur.first == 0) cur.first = 1;
            else if(cur.first == 1) cur.first = 0;
        }
        cur.second ^= 1;
        if(cur == orig) break;
        pos.push_back(cur.first);
    }
    int m = pos.size();
    cout << pos[n % m] << '\n';
}