//
// b.cpp
// Created by wasifshahzad on 12/13/25 at 17:20:44.
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
    int n;
    cin >> n;
    vector<vector<int>> ans(n, vector<int>(n, -1));
    ans[0][(n - 1) / 2] = 1;
    int k = 1, r = 0, c = (n - 1) / 2;
    for(int i = 0; i < n * n - 1; i++) {
        int nr = ((r - 1) % n + n) % n;
        int nc = ((c + 1) % n);
        if(ans[nr][nc] == -1) {
            ans[nr][nc] = ++k;
            r = nr, c = nc;
        } else {
            r = (r + 1) % n;
            ans[r][c] = ++k;
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << ans[i][j] << " ";
        }
        cout << '\n';
    }
}