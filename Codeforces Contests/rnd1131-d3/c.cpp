#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int k = -1;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if (i > 0 && a[i] > 1 && k == -1 && i + 1 < n) {
            k = i;
        }
    }
    if (k == -1) {
        if (a[0] > 1 && a[n - 1] > 1) {
            cout << a[0] + a[n - 1] - 1 << '\n';
        } else if(a[0] > 1) {
            cout << a[0] << '\n';
        } else if(a[n - 1] > 1) {
            cout << a[n - 1] << '\n';
        } else {
            cout << -1 << '\n';
        }
        return;
    }
    for(int i = k; i + 1 < n; i++) {
        a[k - 1]++;
        a[i + 1] += a[i] - 1;
    }
    for(int i = k - 1; i > 0; i--) {
        a[n - 1]++;
        a[i - 1] += a[i] - 1;
    }
    cout << a[0] + a[n - 1] - 1 << '\n';
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
