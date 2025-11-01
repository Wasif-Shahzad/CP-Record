//
// 1749C.cpp
// Created by wasifshahzad on 8/27/25 at 10:58:48.
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
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        auto f = [&] (int k) -> bool {
            multiset<int> ms(a.begin(), a.end());
            for (int x = k; x > 0; x--) {
                auto it = ms.upper_bound(x);
                if (it == ms.begin()) return false;
                it--;
                ms.erase(ms.find(*it));
                if (!ms.empty()) {
                    int mn = *ms.begin();
                    ms.erase(ms.find(mn));
                    ms.insert(mn + x);
                }
            }
            return true;
        };
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            if (f(i)) ans = i;
        }
        cout << ans << '\n';
    }
}