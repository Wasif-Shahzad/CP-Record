//
// c.cpp
// Created by Wasif on 10/10/25 at 19:25:18.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<int> prefix_function(string s) {
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    while(cin >> s) {
        auto pi = prefix_function(s);
        int ans = 0;
        for(int i : pi) {
            ans += i * (i + 1) / 2;
        }
        cout << ans << '\n';
    }
}