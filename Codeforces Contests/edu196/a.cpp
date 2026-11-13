#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int l, r;
    cin >> l >> r;
    if (l <= 0 && r >= 0) {
        cout << max(0ll, abs(abs(r) - abs(l)) - 1) << '\n';
    } else {
        cout << abs(l - r) << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
