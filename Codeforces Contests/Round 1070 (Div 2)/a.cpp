//
// a.cpp
// Created by Wasif on 12/11/25 at 19:31:24.
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
        int n;
        cin >> n;
        vector<int> f(n + 1, 0);
        int ans = 0;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            bool can = false;
            for(int j = x + 1; j <= n; j++) {
                if(f[j]) {
                    can = true;
                    break;
                }
            }
            if(can) {
                ans++;
            } else {
                f[x]++;
            }
        }
        cout << ans << '\n';
    }
}