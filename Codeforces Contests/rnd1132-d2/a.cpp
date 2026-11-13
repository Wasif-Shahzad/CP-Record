#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &i: a) cin >> i;
    sort(a.rbegin(), a.rend());
    int x = 0, y = 0;
    for(int i = 0; i < n; i++) {
        if (x <= y) x += (1ll << a[i]);
        else y += (1ll << a[i]);
    }
    cout << x * y << '\n';
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
