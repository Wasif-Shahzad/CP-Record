//
// 1998C.cpp
// Created by wasifshahzad on 06/16/26 at 14:02:18.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

// [2, 4, 5, 5]
// [2, 5, 5, 5]
// 

void solve() {
    // max median + max value?
    // max median is easy binary search
    // we may have to change the definition of median
    // for odd n, we need to target the (n / 2 -1)th index, nothing changes for even n 
    int n, k;
    cin >> n >> k;
    vector<array<int, 2>> a(n);
    for(int i = 0; i < n; i++) cin >> a[i][0];
    for(int i = 0; i < n; i++) cin >> a[i][1];
    sort(all(a));
    int lg = n - (n - 1) / 2;
    auto get_lo = [&] () -> int {
        auto f = [&] (int x) -> bool {
            int ops = 0, rem = lg;
            for(int i = n - 1; i >= 0; i--) {
                if(rem == 0) break;
                if(a[i][0] >= x) {
                    rem--;
                    continue;
                }
                if(!a[i][1]) continue;
                ops += x - a[i][0];
                rem--;
            }
            return rem == 0 && ops <= k;
        };
        int lo = 1, hi = 3e9;
        while(hi > lo + 1) {
            int mid = (lo + hi) / 2;
            if(f(mid)) lo = mid;
            else hi = mid;
        }
        return lo;
    };
    auto get_ans = [&] (int lo, int lg) -> int {
        int rem = lg;
        int tmpk = k;
        auto ta = a;
        for(int i = n - 1; i >= 0; i--) {
            if(rem == 0) break;
            if(ta[i][0] >= lo) {
                rem--;
                continue;
            }
            if(!ta[i][1]) continue;
            int need = lo - ta[i][0];
            need = min(need, tmpk);
            ta[i][0] += need;
            tmpk -= need;
            rem--;
        }
        sort(all(ta));
        if(tmpk > 0) {
            for(int i = n - 1; i >= 0; i--) {
                if(ta[i][1]) {
                    ta[i][0] += tmpk;
                    break;
                }
            }
            sort(all(ta));
        }
        int ans = ta[n / 2 - 1][0] + ta[n - 1][0];
        ans = max(ans, ta[0][0] + ta[n / 2][0]);
        return ans;
    };
    auto solve_median = [&] () -> int {
        int lo = get_lo();
        int ans = get_ans(lo, lg);
        if(n & 1) lg++;
        lo = get_lo();
        ans = max(ans, get_ans(lo, lg));
        return ans;
    };
    int ans = solve_median();
    for(int i = n - 1; i >= 0; i--) {
        if(a[i][1]) {
            a[i][0] += k;
            k = 0;
            break;
        }
    }
    ans = max(ans, solve_median());
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}