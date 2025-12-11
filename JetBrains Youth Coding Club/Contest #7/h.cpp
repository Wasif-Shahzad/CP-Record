//
// h.cpp
// Created by Wasif on 11/27/25 at 21:16:17.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
int f1(int l, int r);
int f2(int l, int r);

int n, mat[501][501], dp1[501][501], dp2[501][501], mod = 1e9+7;

int f1(int l, int r) {
    if(r == l + 1) return mat[l][r];
    if(l == r) return 1;
    if(dp1[l][r] != -1) return dp1[l][r];
    int ans = 0;
    if(mat[l][r]) {
        ans = (ans + f2(l, r)) % mod;
    }
    for(int i = r - 1; i >= l; i--) {
        if(mat[l][i]) {
            int left = f2(l, i);
            int right = f1(i, r);
            ans = (ans + ((left * right) % mod)) % mod;
        }
    }
    return dp1[l][r] = ans;
}

int f2(int l, int r) {
    if(r == l + 1) return 1;
    if(l == r) return 1;
    if(!mat[l][r]) return 0;
    if(dp2[l][r] != -1) return dp2[l][r];
    int ans = 0;
    for(int i = r - 1; i >= l; i--) {
        if(mat[l][i]) {
            int left = f2(l, i);
            int right = f1(i + 1, r);
            ans = (ans + ((left * right) % mod)) % mod;
        }
    }
    return dp2[l][r] = ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    memset(dp1, -1, sizeof(dp1));
    memset(dp2, -1, sizeof(dp2));

    cout << f1(0, n - 1) << '\n';
}