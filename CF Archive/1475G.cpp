//
// 1475G.cpp
// Created by Wasif on 12/11/25 at 14:13:13.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int N = 2e5;
int dp[N + 1], f[N + 1];


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            f[a[i]]++;
        }
        sort(a.begin(), a.end());
        for(int i = N; i > 0; i--) {
            for(int j = 2 * i; j <= N; j += i) {
                dp[i] = max(dp[i], dp[j]);
            }
            dp[i] += f[i];
        }
        cout << n - *max_element(dp, dp + N) << '\n';
        for(int i = 0; i <= N; i++) {
            dp[i] = f[i] = 0;
        }
    }
}