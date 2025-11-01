//
// a.cpp
// Created by Wasif on 10/28/25 at 19:34:15.
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
        set<int> s;
        for(int i = 0; i < 4; i++) {
            int x; cin >> x;
            s.insert(x);
        }
        if(s.size() == 1) {
            cout << "Yes\n";
        } else {
            cout << "NO\n";
        }
    }
}