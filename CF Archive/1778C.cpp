#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    string a, b;
    cin >> a >> b;
    vector<vector<int>> ind(26);
    vector<int> diff;
    for(int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            diff.push_back(a[i] - 'a');
            ind[a[i] - 'a'].push_back(i);
        }
    }
    sort(diff.begin(), diff.end());
    diff.erase(unique(diff.begin(), diff.end()), diff.end());
    int ans = 0, m = (int)diff.size();
    if (k >= m) {
        cout << n * (n + 1) / 2 << '\n';
        return;
    }
    if (k > 0) {
        int mask = (1ll << k) - 1;
        while (mask < (1 << m)) {
            string tmp = a;
            for(int j = 0; j < m; j++) {
                if ((1ll << j) & mask) {
                    for(int i: ind[diff[j]]) tmp[i] = b[i];
                }
            }
            int cnt = 0, here = 0;
            for(int i = 0; i < n; i++) {
                if (tmp[i] != b[i]) {
                    here += cnt * (cnt + 1) / 2;
                    cnt = 0;
                } else {
                    cnt++;
                }
            }
            if (cnt > 0) here += cnt * (cnt + 1) / 2;
            ans = max(ans, here);

            int c = mask & -mask;
            int r = mask + c;
            mask = (((r ^ mask) >> 2) / c) | r;
        }
    }
    int cnt = 0, here = 0;
    for(int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            here += cnt * (cnt + 1) / 2;
            cnt = 0;
        } else {
            cnt++;
        }
    }
    if (cnt > 0) here += cnt * (cnt + 1) / 2;
    ans = max(ans, here);
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
