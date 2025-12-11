//
// 2157E.cpp
// Created by Wasif on 12/02/25 at 18:42:22.
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
        vector<int> f(3 * n + 1, 0);
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            f[x]++;
        }
        int ans = 0;
        stack<pair<int, int>> bg;
        for(int i = 3 * n; i > 0; i--) {
            if(f[i] <= k) {
                if(f[i] != 1) bg.push({f[i], i});
                continue;
            }
            int cur = f[i] - 1;
            int j = i;
            while(bg.size()) {
                auto [v, loc] = bg.top();
                bg.pop();
                v += cur;
                if(v <= k) {
                    j = loc;
                    break;
                }
                v--;
                cur = v;
                j = loc;
            }
            ans = max(ans, j - i);
            if(cur != 1) bg.push({cur, j});
        }
        cout << ans << '\n';
    }
}