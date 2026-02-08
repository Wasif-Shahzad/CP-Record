//
// e.cpp
// Created by wasifshahzad on 01/01/26 at 21:40:17.
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
        vector<int> a(n), loc(n + 1);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            loc[a[i]] = i;
        }
        int j = n;
        for(int i = n; i > 0; i--) {
            if(loc[i] > j) continue;
            for(int k = loc[i]; k < j; k++) cout << a[k] << " ";
            j = loc[i];
        }
        cout << '\n';
    }
}