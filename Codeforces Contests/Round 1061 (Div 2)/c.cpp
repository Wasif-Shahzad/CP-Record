//
// c.cpp
// Created by Wasif on 10/24/25 at 19:32:59.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n), cnt(n + 1, 0), suff(n + 2, 0);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            cnt[a[i]]++;
        }
        for(int i = n; i > 0; i--) {
            suff[i] = suff[i + 1] + cnt[i];
        }
        int ans = 1;
        for(int i = n; i >= 0; i--) {
            int have = cnt[i];
            if(2 * i <= n) have += cnt[2 * i];
            if(3 * i <= n) have += cnt[3 * i];
            if(4 * i <= n) have += suff[4 * i];
            int rem = n - have;
            if(rem <= k) {
                ans = i;
                break;
            }
        }
        cout << ans << '\n';
    }
}