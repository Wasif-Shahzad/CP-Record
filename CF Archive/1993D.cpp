#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if(k > n) {
        sort(all(a));
        cout << a[(n - 1) / 2] << '\n';
        return;
    }
    const int oo = 1e7;
    auto f = [&] (int x) -> bool {
        vector<int> b(n + 1);
        for(int i = 1; i <= n; i++) {
            b[i] = (a[i - 1] >= x ? 1 : -1);
        }
        // how to make sure <= k elems remaining?
        // exactly n % k elems remain
        // we want to have min sum to be removed (-ve)
        // each removed subarray is independent
        // we wanna remove floor(n / k) subarrays now with min total sum
        // if index i goes to index j. elements taken before i are j - 1. so elements removed are (i - 1) - (j - 1) = i - j
        // (i - j) mod k = 0 => i mod k = j mod k
        vector<int> dp(n + 1, -oo);
        int lim = n % k;
        auto go = [&] (int i, auto&& self) -> int {
            if(lim != 0 && i % k > lim) return 0;
            if(i == n + 1) return 0;
            if(dp[i] != -oo) return dp[i];
            int pick = b[i];
            if(i == 2) {
                // cout << pick << '\n';
            }
            if(lim == 0) {
                if(i % k != 0) {
                    pick += self(i + 1, self);
                } 
            } else {
                if(i % k < lim) {
                    pick += self(i + 1, self);
                }
            }
            int notPick;
            if(i + k <= n) notPick = self(i + k, self);
            else notPick = -n - 10;
            // if(i == 5) cout << pick << " " << notPick << '\n';
            return dp[i] = max(pick, notPick);
        };
        // int res = go(1, go);
        // cout << res << '\n';
        // for(int i = 1; i <= n; i++) cout << dp[i] << " ";
        // cout << '\n';
        int len = n % k;
        if(len == 0) len += k;
        return go(1, go) > 0;
    };
    // cout << f(6) << '\n';
    int lo = 1, hi = 1;
    while(f(hi)) hi *= 2;
    while(hi > lo + 1) {
        int mid = (hi + lo) / 2;
        if(f(mid)) lo = mid;
        else hi = mid;
    }
    cout << lo << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}
