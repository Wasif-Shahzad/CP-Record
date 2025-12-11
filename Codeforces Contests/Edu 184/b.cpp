//
// b.cpp
// Created by Wasif on 11/14/25 at 19:24:28.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    for(int i = 0; i + 1 < n; i++) {
        if(s[i] == '*' && s[i] == s[i + 1]) {
            cout << -1 << '\n';
            return;
        }
        if(s[i] == '>' && s[i + 1] == '*') {
            cout << -1 << '\n';
            return;
        }
        if(s[i + 1] == '<' && s[i] == '*') {
            cout << -1 << '\n';
            return;
        }
        if(s[i] == '>' && s[i + 1] == '<') {
            cout << -1 << '\n';
            return;
        }
    }
    int j = -1;
    for(int i = 0; i < n; i++) {
        if(s[i] == '>') {
            j = i;
            break;
        }
    }
    if(j == -1 || j == 0) {
        cout << n << '\n';
        return;
    }
    int len1 = j, len2 = n - j;
    if(s[j - 1] == '*') len2++;
    cout << max(len1, len2) << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solve();
}