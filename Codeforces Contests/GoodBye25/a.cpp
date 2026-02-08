//
// a.cpp
// Created by wasifshahzad on 12/27/25 at 19:28:38.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        string s;
        cin >> s;
        if(count(s.begin(), s.end(), 'Y') > 1) cout << "NO\n";
        else cout << "YES\n";
    }
}