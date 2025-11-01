//
// b.cpp
// Created by Wasif on 10/06/25 at 19:16:50.
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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        if(n == k) {
            cout << string(n, '-') << '\n';
            continue;
        } else {
            int c0 = count(s.begin(), s.end(), '0');
            int c1 = count(s.begin(), s.end(), '1');
            int c2 = count(s.begin(), s.end(), '2');
            int l = c0 + c2 + 1;
            int r = n - k + c0;
            for(int i = 1; i <= n; i++) {
                if(i <= c0 || i > n - c1) cout << '-';
                else if(l <= i && i <= r) cout << '+';
                else cout << '?';
            }
            cout << '\n';
        }
    }
}