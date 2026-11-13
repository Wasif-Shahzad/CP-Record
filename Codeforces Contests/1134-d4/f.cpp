#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int sum = 0;
    for(int &i: a) cin >> i, sum += i;
    if (sum != 0) {
        cout << -1 << '\n';
        return;
    }
    int k = 0;
    vector<int> ans(n, -1);
    for(int i = 0; i < n; i++) {
        int cur = -n + 1 + 2 * i;
        int diff = a[i] - cur;
        // cerr << i << " " << cur << " " << diff << '\n';
        if (i + diff < 0 || i + diff > n || ans[i + diff] != -1) {
            cout << -1 << '\n';
            return;
        }
        ans[i + diff] = i + 1;
        k++;
    }
    for(int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';
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
