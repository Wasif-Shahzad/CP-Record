//
// h.cpp
// Created by Wasif on 10/17/25 at 20:17:57.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MAXN = 2005;
using bs = bitset<MAXN>;

vector<pair<int, int>> mergeIntervals(vector<pair<int, int>>& intervals) {
    if (intervals.empty()) {
        return {};
    }
    sort(intervals.begin(), intervals.end());
    vector<pair<int, int>> merged;
    for (const auto& interval : intervals) {
        if (merged.empty() || interval.first > merged.back().second) {
            merged.push_back(interval);
        } else {
            merged.back().second = max(merged.back().second, interval.second);
        }
    }
    return merged;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    bs dp;
    int T;
    cin >> T;
    while(T--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<pair<int, int>> intervals(m);
        vector<vector<int>> r(n + 1), l(n + 1);
        for(int i = 0; i < m; i++) {
            cin >> intervals[i].first >> intervals[i].second;
            intervals[i].first--;
            intervals[i].second--;
            r[intervals[i].first].push_back(intervals[i].second);
            l[intervals[i].second].push_back(intervals[i].first);
        }
        set<pair<int, int>> active;
        vector<int> con(n, 0);
        for(int i = 0; i < n; i++) {
            for(int R: r[i]) active.insert({i, R});
            con[i] = (int)active.size();
            for(int L: l[i]) active.erase({L, i});
        }
        vector<pair<int, int>> has;
        for(int i = 0; i < n; i++) {
            if(con[i]) has.push_back({con[i], i});
        }
        sort(has.rbegin(), has.rend());
        for(int x = 1; x <= n; x++) {
            int eq = 0, sm = 0, lg = 0;
            for(int i = 0; i < n; i++) {
                if(a[i] == x) eq++;
                else if(a[i] < x) sm++;
                else lg++;
            }
            vector<int> bad(n, 0);
            for(int i = 0; i < min(eq, (int)has.size()); i++) {
                bad[has[i].second] = 1;
            }
            active = {};
            vector<int> pref(n, 0);
            pref[0] = bad[0];
            for(int i = 1; i < n; i++) {
                pref[i] = bad[i] + pref[i - 1];
            }
            vector<pair<int, int>> valid;
            for(auto [L, R]: intervals) {
                int sum = pref[R] - (L ? pref[L - 1] : 0);
                if(sum == 0) valid.push_back({L, R});
            }
            if(valid.size() == 0) {
                cout << 1;
                continue;
            }

            auto merged = mergeIntervals(valid);
            vector<int> lens;
            int total = 0;
            for(auto [L, R]: merged) {
                lens.push_back(R - L + 1);
                total += lens.back();
            }

            for(int i = 0; i <= n; i++) {
                dp[i] = 0;
            }

            dp[0] = 1;
            for(int len: lens) {
                dp |= dp << len;
            }

            bool good = false;
            for(int i = 1; i <= n; i++) {
                if(dp[i]) {
                    int rem = total - i;
                    if(i <= sm && rem <= lg) {
                        good = true;
                        break;
                    }
                    if(i <= lg && rem <= sm) {
                        good = true;
                        break;
                    }
                }
            }
            cout << (good ? 1 : 0);
        }
        cout << '\n';
    }
}