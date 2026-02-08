//
// b.cpp
// Created by wasifshahzad on 12/19/25 at 19:39:36.
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
        int n;
        cin >> n;
        vector<string> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        string s = a[0];
        for(int i = 1; i < n; i++) {
            if(s + a[i] < a[i] + s) s += a[i];
            else s = a[i] + s;
        }
        cout << s << '\n';
    }
}