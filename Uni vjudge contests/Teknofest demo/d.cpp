//
// d.cpp
// Created by wasifshahzad on 01/01/26 at 21:18:00.
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
        int n, m;
        cin >> n >> m;
        vector<vector<char>> a(n, vector<char>(m, 'B'));
        if(n == 2) {
            a[n - 1][m - 1] = 'W';
        } else {
            a[n - 1][m - 1] = a[n - 2][m - 1] = 'W';
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) cout << a[i][j];
            cout << '\n';
        }
    }
}