//
// 1969D.cpp
// Created by wasifshahzad on 8/20/25 at 16:02:57.
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
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(n);
        vector<pair<int, int>> opt;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> b[i];
            if (b[i] >= a[i]) {
                opt.push_back({a[i], b[i]});
            }
        }
        n = opt.size();
        priority_queue<int, vector<int>, greater<>> pq;
        sort(opt.begin(), opt.end());
        int sa = 0, sb = 0;
        int lose = 0, ans = 0;
        for (int i = 0; i < n; i++) {
            sa += opt[i].first;
            sb += opt[i].second;
            if (pq.size() < k) {
                pq.push(opt[i].second);
                lose += opt[i].second;
                continue;
            }
            if (!pq.empty() && opt[i].second > pq.top()) {
                lose -= pq.top();
                pq.pop();
                lose += opt[i].second;
                pq.push(opt[i].second);
            }
            const int rem = sb - lose;
            ans = max(ans, rem - sa);
        }
        cout << ans << '\n';
    }
}