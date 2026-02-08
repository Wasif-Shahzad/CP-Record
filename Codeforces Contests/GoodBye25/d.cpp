//
// d.cpp
// Created by wasifshahzad on 12/27/25 at 20:50:41.
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
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        vector<pair<int, int>> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        if(m > n / 2) {
            cout << -1 << '\n';
            continue;
        }
        vector<pair<int, int>> ans;
        if(m == 0) {
            // special
            int tot = 0;
            sort(a.begin(), a.end());
            for(int i = 0; i + 1 < n; i++) tot += a[i].first;
            if(tot < a[n - 1].first) {
                cout << -1 << '\n';
                continue;
            }
            for(int i = 0; i + 1 < n; i++) {
                if(tot - a[i].first >= a[n - 1].first) {
                    ans.push_back({a[i].second, a[i + 1].second});
                    tot -= a[i].first;
                } else {
                    ans.push_back({a[i].second, a[n - 1].second});
                } 
            }
            cout << ans.size() << "\n";
            for(auto [i, j]: ans) cout << i + 1 << " " << j + 1 << '\n';
            continue;
        }
        sort(a.rbegin(), a.rend());
        while(n > 2 * m) {
            // attack to 2nd min by min
            auto [v, i] = a.back();
            auto [v2, j] = a[n - 2];
            ans.push_back({i, j});
            a.pop_back();
            n--;
            a[n - 1].first -= v;
        }
        for(int k = n - 2; k >= 0; k -= 2) {
            auto [v, i] = a[k];
            auto [v2, j] = a[k + 1];
            ans.push_back({i, j});
        }
        cout << ans.size() << '\n';
        for(auto [i, j]: ans) cout << i + 1 << " " << j + 1 << '\n';
    }
}