//
// b.cpp
// Created by Wasif on 10/11/25 at 16:51:22.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> cur{1};
    for(int i = 1; i <= n; i++) {
        int v = 0;
        for(int j = 0; j < cur.size(); j++) {
            int t = cur[j];
            while(t > 0) {
                v += t % 10;
                t /= 10;
            }
        }   
        cur.push_back(v);
    }
    cout << cur.back();
}