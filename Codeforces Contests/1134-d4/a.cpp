#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    if (a > b) swap(a, b);
    if (b > c) swap(b, c);
    if (a > b) swap(a, b);
    if (a == b - 1 && c == b + 1) cout << "Yes\n";
    else cout << "No\n";
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
