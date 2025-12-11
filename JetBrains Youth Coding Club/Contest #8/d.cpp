//
// d.cpp
// Created by Wasif on 12/02/25 at 09:52:53.
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
    string s;
    cin >> n >> s;
    int x = -1, y = -1;
    for(int i = 0; i < n; i++) {
        if(s[i] == 'R') {
            x = i;
            break;
        }
    }
    for(int i = n - 1; i > max(x, 0ll); i--) {
        if(s[i] == 'L' && s[i - 1] == 'R') {
            y = i - 1;
            break;
        }
    }
    if(x == -1 || y == -1) {
        // all l's, all r's
        if(x == -1) {
            for(int i = n - 1; i > 0; i--) {
                if(s[i] == 'L') {
                    if(s[i] == 'L' && x == -1) x = i;
                    y = i - 1;
                }
            }
        } else {
            for(int i = 0; i < n; i++) {
                if(s[i] == 'R') y = i + 1;
            }
        }
    }
    cout << x + 1 << " " << y + 1 << '\n';
}