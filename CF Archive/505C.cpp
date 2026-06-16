//
// 505C.cpp
// Created by wasifshahzad on 05/26/26 at 13:04:26.
//

#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

const int N = 3e4;
int loc[N + 1];


void solve() {
    int n, d;
    cin >> n >> d;
    set<int> ss;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        loc[x]++;
        ss.insert(x);
    }
    int tmp = d;
    int r = d, s = d;
    while(s < N) s += ++tmp, r++;
    tmp = d;
    int l = d; s = d;
    while(l > 0 && s < N) s += --tmp, l--;
    if(l == 0) l = 1;
    int m = r - l + 1;
    int dp[N + 1][m + 1];
    for(int i = N; i >= d; i--) {
        for(int j = l; j <= r; j++) {
            dp[i][j - l] = loc[i];
            if(i + j <= N) dp[i][j - l] += dp[i + j][j - l];
            if(j > l && i + j - 1 <= N) dp[i][j - l] = max(dp[i][j - l], loc[i] + dp[i + j - 1][j - 1 - l]);
            if(j < r && i + j + 1 <= N) dp[i][j - l] = max(dp[i][j - l], loc[i] + dp[i + j + 1][j + 1 - l]);
        }
    }
    cout << dp[d][d - l] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}