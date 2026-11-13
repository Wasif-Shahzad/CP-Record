#include <bits/stdc++.h>
using namespace std;
// #define int long long

void chkmax(int &a, int b) {
    a = max(a, b);
}

void solve() {
    string a, b;
    cin >> a >> b;
    int n = a.size(), m = b.size();
    // sa[i] - sa[j + 1] = sb[x] - sb[y + 1]
    // sa[i] - sb[x] = sa[j + 1] - sb[y + 1]
    vector<int> sa(n + 1, 0), sb(m + 1, 0);
    for(int i = n - 1; i >= 0; i--) {
        sa[i] = a[i] - '0';
        sa[i] = (sa[i] + sa[i + 1]) % 10;
    }
    for(int i = m - 1; i >= 0; i--) {
        sb[i] = b[i] - '0';
        sb[i] = (sb[i] + sb[i + 1]) % 10;
    }
    if (sa[0] != sb[0]) {
        cout << -1 << '\n';
        return;
    }
    vector<array<int, 10>> best(m + 1, {0}), cur(m + 1, {0});
    int ans = 0;
    for(int i = n - 1; i >= 0; i--) {
        cur.assign(m + 1, {0});
        for(int j = m - 1; j >= 0; j--) {
            int D = (sa[i] - sb[j] + 10) % 10;
            int here = 1 + best[j + 1][D];
            if (i == 0 && j == 0) ans = here;
            for(int r = 0; r < 10; r++) {
                chkmax(cur[j][r], best[j][r]);
                chkmax(cur[j][r], cur[j + 1][r]);
            }
            chkmax(cur[j][D], here);
        }
        best.swap(cur);
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
