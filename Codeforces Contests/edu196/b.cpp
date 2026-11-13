#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int ans = n - 1;
    for(int &i: a) cin >> i;
    for(int i = 0; i < n; i++) {
        int c = 0;
        for(int j = 0; j < n; j++) {
            if (a[j] % a[i] == 0) c++;
        }
        ans = min(ans, n - c);
    }
    cout << ans << '\n';
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
