//
// A.cpp
// Created by wasifshahzad on 8/21/25 at 21:05:24.
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
        string s;
        cin >> s;
        int m;
        cin >> m;
        string a, b;
        cin >> a >> b;
        for (int i = 0; i < m; i++) {
            if (b[i] == 'V') {
                s = a[i] + s;
            } else {
                s += a[i];
            }
        }
        cout << s << '\n';
    }
}