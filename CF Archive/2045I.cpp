//
// 2045I.cpp
// Created by Wasif on 10/13/25 at 18:44:52.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

struct FenwickTree {
    vector<int> bit;
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> const &a) : FenwickTree(a.size()) {
        for (int i = 0; i < n; i++) {
            bit[i] += a[i];
            int r = i | (i + 1);
            if (r < n) bit[r] += bit[i];
        }
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> cnt(m + 1, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]] = 1;
    }
    int distinct = accumulate(cnt.begin(), cnt.end(), 0ll);
    vector<int> lst(m + 1, -1);
    vector<int> loc(n, 0);
    FenwickTree fenwick(loc);
    int ans = 0;
    for(int i = 1; i <= m; i++) {
        if(cnt[i] == 0) {
            ans += distinct;
        }
    }
    for(int i = 0; i < n; i++) {
        if(lst[a[i]] == -1) {
            int prev = (i ? fenwick.sum(i - 1) : 0);
            int rem = distinct - prev - 1;
            ans += 2 * rem;
            fenwick.add(i, 1);
        } else {
            int l = lst[a[i]];
            int inside = fenwick.sum(l + 1, i - 1);
            ans += inside;
            fenwick.add(l, -1);
            fenwick.add(i, 1);
        }
        cout << i << " " << ans << '\n';
        lst[a[i]] = i;
    }
    cout << ans << '\n';
}