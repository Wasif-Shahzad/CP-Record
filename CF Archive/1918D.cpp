//
// 1918D.cpp
// Created by Wasif on 10/08/25 at 20:38:33.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

// Using a pair to store both the value and its original index
template <typename T>
using ValueIndexPair = pair<T, int>;

template <typename T>
struct SparseTable {
    vector<vector<ValueIndexPair<T>>> st;
    vector<int> log_table;
    int n;

    // Constructor: Pre-processes the array in O(n log n)
    SparseTable(const vector<T>& v) {
        n = v.size();
        if (n == 0) return;

        // Pre-compute logs for O(1) length calculations
        log_table.resize(n + 1);
        log_table[1] = 0;
        for (int i = 2; i <= n; i++) {
            log_table[i] = log_table[i / 2] + 1;
        }

        // Initialize sparse table
        int max_log = log_table[n];
        st.resize(max_log + 1, vector<ValueIndexPair<T>>(n));

        // Base case: ranges of length 2^0 = 1
        // Store the value and its original index
        for (int i = 0; i < n; i++) {
            st[0][i] = {v[i], i};
        }

        // DP to build the rest of the table
        for (int i = 1; i <= max_log; i++) {
            for (int j = 0; j + (1 << i) <= n; j++) {
                // The min of two pairs is determined lexicographically.
                // It first compares the .first elements (the values).
                // If they are equal, it compares the .second elements (the indices).
                // This correctly finds the minimum value, and the one with the smallest index in case of ties.
                st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
            }
        }
    }

    // Query: Answers the minimum {value, index} of range [l, r] (inclusive) in O(1)
    ValueIndexPair<T> query(int l, int r) {
        if (l > r || l < 0 || r >= n) {
            // Return an identity element: max value and invalid index
            return {numeric_limits<T>::max(), -1};
        }
        int len = r - l + 1;
        int k = log_table[len];
        // Minimum of two overlapping ranges that cover [l, r]
        return min(st[k][l], st[k][r - (1 << k) + 1]);
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> a(n + 1, 0), pref(n + 1, 0);
        map<int, vector<int>> loc;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
            pref[i] = pref[i - 1] + a[i];
            loc[a[i]].push_back(i);
        }
        SparseTable<int> table(a);
        auto f = [&] (int x) -> bool{
            int cur_sum = 0, k = 1, extra = 0;
            for(int i = 1; i <= n; i++) {
                if(a[i] > x) return false;
            }
            for(int i = 1; i <= n; i++) {
                if(cur_sum + a[i] <= x) {
                    cur_sum += a[i];
                    continue;
                }
                int l = k, r = i;
                while(r > l + 1) {
                    int m = (l + r) / 2;
                    int suff = pref[i - 1] - (m > 0 ? pref[m - 1] : 0);
                    int here = suff + a[i];
                    if(here <= x) r = m;
                    else l = m;
                }
                // l is the first element which can be removed
                auto [mn, j] = table.query(l, i);
                auto it = upper_bound(loc[mn].begin(), loc[mn].end(), i);
                it--;
                j = *it;
                int suff = pref[i - 1] - pref[j];
                if(j != i) suff += a[i];
                cur_sum = suff;
                k = i + 1;
                extra += mn;
            }
            return extra <= x;
        };
        cout << f(6);
        // int lo = 0, hi = 1;
        // while(!f(hi)) hi *= 2;
        // while(hi > lo + 1) {
        //     int mid = (hi + lo) / 2;
        //     if(f(mid)) hi = mid;
        //     else lo = mid;
        // }
        // cout << hi << '\n';
    }
}