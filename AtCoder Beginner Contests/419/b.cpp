//
// Created by wasifshahzad on 8/16/25.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    multiset<int> s;
    while (q--) {
        int t;
        cin >> t;
        if (t == 1) {
            int x; cin >> x;
            s.insert(x);
        } else {
            cout << *s.begin() << '\n';
            s.erase(s.find(*s.begin()));
        }
    }
}