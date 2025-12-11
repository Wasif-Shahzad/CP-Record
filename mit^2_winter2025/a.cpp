//
// a.cpp
// Created by Wasif on 12/07/25 at 22:57:52.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<vector<char>> a(n, vector<char>(n, '.'));
        for(int i = 0; i < n; i++) {
            a[i][0] = a[i][n - 1] = '#';
        }   
        for(int i = 1; i <= n / 2; i++) {
            a[i][i] = a[i][n - i - 1] = '#';
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) cout << a[i][j];
            cout << '\n';
        }
    }
}