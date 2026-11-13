#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    for(string &i: a) cin >> i;
    // if (i, j) have ham = m, we overcount m * (m - 1) / 2 + m + 1
    // we subtract m * (m - 1) / 2 + m
    // if (i, j) have ham = m - 1, we overcount them 1 + m - 1 times
    // we subtract m - 1 to get 1
    vector<unordered_map<string, int>> f(1 << m);
    int lim = m - 2, ans = 0;
    for(int i = n - 1; i >= 0; i--) {
        for(int mask = 0; mask < (1 << m); mask++) {
            int x = __builtin_popcount(mask);
            if (x < lim) continue;
            string rem = "";
            for(int j = 0; j < m; j++) {
                if ((1 << j) & mask) rem += a[i][j];
            }
            if (f[mask][rem] > 0) {
                ans += f[mask][rem];
                if (x == m - 1) ans -= f[mask][rem] * (m - 1);
                else if (x == m) ans -= f[mask][rem] * m * (3 - m) / 2;
            }
        }
        for(int mask = 0; mask < (1 << m); mask++) {
            if (__builtin_popcount(mask) < lim) continue;
            string rem = "";
            for(int j = 0; j < m; j++) {
                if ((1 << j) & mask) rem += a[i][j];
            }
            f[mask][rem]++;
        }
    }
    cout << ans << '\n';
}
