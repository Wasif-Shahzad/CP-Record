//
// 1364C.cpp
// Created by wasifshahzad on 8/27/25 at 10:45:00.
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
    while (T--) {
        int n;
        cin >> n;
        vector<int> ans;
        while (n > 1) {
            if (__builtin_popcount(n) == 1) {
                ans.push_back(n);
                n /= 2;
                continue;
            }
            for (int j = 0; j <= 30; j++) {
                if ((1 << j) & n) {
                    ans.push_back(n);
                    n -= (1 << j);
                    break;
                }
            }
        }
        ans.push_back(1);
        cout << ans.size() << '\n';
        for (const int x: ans) cout << x << " ";
        cout << '\n';
    }
}