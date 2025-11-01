//
// d.cpp
// Created by Wasif on 10/19/25 at 09:55:50.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();
    int l = -1, r = -1;
    for(int i = 0; i < n; i++) {
        if(s[i] != 'a') {
            l = i;
            break;
        }
    }
    if(l == -1) {
        s.back() = 'z';
        cout << s << '\n';
        return 0;
    }
    r = n - 1;
    for(int i = l + 1; i < n; i++) {
        if(s[i] == 'a') {
            r = i - 1;
            break;
        }
    }
    for(int i = l; i <= r; i++) {
        s[i] = char(s[i] - 1);
    }
    cout << s << '\n';
}