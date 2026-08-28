#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    // is it that we're supposed to choose adjacent elements?
    // our final sum is len * (a[i] - a[j])
    // check operations for each lenght one by one in ascending order? this would be n^2
    // i think this works but too slow
    // [x, y, z] x < y < z
    // if y > x - z then length 2 *maybe*
    // else length 3
    // [y, x, z] => 2 * x - 2 * z > x + z
    // x > 3 * z
    // we can get n * max wtf, it would be easy
    // make everything on left, right zero
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }
    if(n == 2) {
        cout << max(sum, 2 * abs(a[0] - a[1])) << '\n';
        return;
    }
    if(n == 3) {
        map<vector<int>, int> has;
        auto solve = [&] (vector<int>& cur, auto&& self) -> int {
            int mx = max({cur[0], cur[1], cur[2]});
            if(cur[0] == mx || cur[2] == mx) return 3 * mx;
            if (has.count(cur)) return has[cur];
            int sum = cur[0] + cur[1] + cur[2];
            auto tmp = cur;
            tmp[0] = tmp[1] = abs(tmp[1] - tmp[0]);
            int left = self(tmp, self);
            tmp = cur;
            tmp[1] = tmp[2] = abs(tmp[2] - tmp[1]);
            int right = self(tmp, self);
            return has[cur] = max({sum, left, right});
        };
        cout << solve(a, solve) << '\n';
        return;
    }
    int mx = *max_element(a.begin(), a.end());
    cout << n * mx << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
