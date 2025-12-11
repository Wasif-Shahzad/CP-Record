//
// a.cpp
// Created by Wasif on 11/28/25 at 19:31:06.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    int k = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            a[i][j] = k++;
        }
    }

    const vector<int> dx= {1, 0, -1, 0};
    const vector<int> dy = {0, 1, 0, -1};

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int here = a[i][j];
            for(k = 0; k < 4; k++) {
                int ni = i + dx[k], nj = j + dy[k];
                if(ni < 0 || nj < 0 || ni >= n || nj >= n) continue;
                here += a[ni][nj];
            }
            ans = max(ans, here);
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solve();
}