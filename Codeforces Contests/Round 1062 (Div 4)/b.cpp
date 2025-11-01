//
// b.cpp
// Created by Wasif on 10/28/25 at 19:38:02.
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
        string s, t;
        cin >> s >> t;
        vector<int> f1(26, 0), f2(26, 0);
        for(int i = 0; i < n; i++) {
            f1[s[i] - 'a']++;
            f2[t[i] - 'a']++;
        }
        cout << (f1 == f2 ? "YES" : "NO") << '\n';
    }
}