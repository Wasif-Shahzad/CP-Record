//
// 1358D.cpp
// Created by wasifshahzad on 03/25/26 at 16:11:15.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

/*
are we supposed to optimize the sliding window brute force somehow?
we can easily solve if we start in the beginning of each month
same if we end in each month
not sure if that's it?
{1, 2, 1, 2, 3, 4, 1, 2, 3, 4, 1, 2, 3, 4, 5}
*/

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> d(n);
    for(int i = 0; i < n; i++) {
        cin >> d[i];
    }
    for(int i = 0; i < n; i++) {
        d.push_back(d[i]);
    }
    n *= 2;
    vector<int> s1(n + 1, 0), s2(n);
    s1[n - 1] = d[n - 1], s2[n - 1] = d[n - 1] * (d[n - 1] + 1) / 2;
    for(int i = n - 2; i >= 0; i--) {
        s1[i] = s1[i + 1], s2[i] = s2[i + 1];
        s1[i] += d[i];
        s2[i] += d[i] * (d[i] + 1) / 2;
    }
    auto gs1 = [&] (int l, int r) -> int {
        int ans = s1[l];
        if(r + 1 < n) ans -= s1[r + 1];
        return ans;
    };
    auto gs2 = [&] (int l, int r) -> int {
        int ans = s2[l];
        if(r + 1 < n) ans -= s2[r + 1];
        return ans;
    };
    int ans = 0;
    auto get_higher = [&] (int x) -> int {
        int lo = 0, hi = n + 1;
        while(hi > lo + 1) {
            int mid = (hi + lo) / 2;
            if(s1[mid] > x) lo = mid;
            else hi = mid;
        }
        return lo;
    };
    auto get_sum = [&] (int i, int r) -> int {
        int l = d[i] - r;
        return d[i] * (d[i] + 1) / 2 - l * (l + 1) / 2;
    };
    for(int i = n - 1; i >= n / 2; i--) {
        int j = get_higher(s1[i] + x - d[i]);
        if(i == j) {
            ans = max(ans, get_sum(i, x));
            continue;
        }
        if(gs1(j + 1, i) == x) {
            ans = max(ans, gs2(j + 1, i));
        } else {
            int cur = gs2(j + 1, i);
            int rem = x - gs1(j + 1, i);
            cur += get_sum(j, rem);
            ans = max(ans, cur);
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}