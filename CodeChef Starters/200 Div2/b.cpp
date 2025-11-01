//
// b.cpp
// Created by wasifshahzad on 8/20/25 at 19:29:00.
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
    while (T--) {
        int n;
        cin >> n;
        vector<int> here(n);
        for (int i = 0; i < n; i++) {
            here[i] = i % 5;
        }
        for (int i = 0; i < n; i++) {
            cout << char('a' + here[i]);
        }
        cout << '\n';
    }
}