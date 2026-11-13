#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].second >> a[i].first;
    }
    sort(a.begin(), a.end());
    int ans = 0, done = 0, i = 0, r = n - 1;
    for(; i < r; i++) {
        int need = max(0ll, a[i].first - done);
        while (r > i && need > 0) {
            int rm = min(a[r].second, need);
            ans += 2 * rm;
            a[r].second -= rm, need -= rm;
            done += rm;
            if (a[r].second == 0) r--;
        }
        if (need > 0) {
            int rm = min(a[i].second, need);
            ans += 2 * rm + a[i].second - rm;
            done += need + a[i].second;
            r--;
            break;
        }
        done += a[i].second;
        ans += a[i].second;
    }
    if (i == r) {
        int need = max(0ll, a[i].first - done);
        int rm = min(a[i].second, need);
        ans += 2 * rm + a[i].second - rm;
    }
    cout << ans << '\n';
}
