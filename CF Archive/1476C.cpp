#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for(int &i: c) cin >> i;
    for(int &i: a) cin >> i;
    for(int &i: b) cin >> i;
    vector<int> ans(n + 1, 0);
    int next = c[n - 1] - 1;
    for(int i = n - 2; i >= 0; i--) {
        // either we start a new cycle here
        // or we continue the previous 1
        int l = a[i + 1], r = b[i + 1];
        if (l > r) swap(l, r);
        ans[i] = next + 2 + r - l;
        // cout << ans[i] << " " << next << '\n';
        if (r != l) next = max(next + 2 + c[i] - 1 - (r - l), c[i] - 1);
        else next = c[i] - 1;
    }
    cout << *max_element(ans.begin(), ans.end()) << '\n';
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
