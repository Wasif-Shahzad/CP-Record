//
// a.cpp
// Created by Wasif on 12/06/25 at 13:10:43.
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
        set<int> s;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            s.insert(x);
        }
        int v = s.size();
        cout << *s.lower_bound(v) << '\n';
    }
}