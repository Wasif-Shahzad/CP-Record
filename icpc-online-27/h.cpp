#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if ((a + b + c) % 3) {
        cout << -1 << '\n';
        return;
    }
    int req = (a + b + c) / 3;
    if (max({a, b, c}) == min({a, b, c})) {
        cout << 0 << '\n';
        return;
    }
    if (a == req || b == req || c == req) {
        cout << 1 << '\n';
    } else {
        cout << 2 << '\n';
    }
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
