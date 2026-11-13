#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int &i: a) cin >> i;
    sort(a.begin(), a.end());
    rotate(a.begin(), a.end() - k, a.end());
    reverse(a.begin() + k, a.end());
    int sum = 0;
    for(int i = 0; i < k; i++) sum += a[i];
    for(int i = k; i < n; i++) {
        if (a[i] * i >= sum) {
            cout << "No\n";
            return;
        }
        sum += a[i];
    }
    cout << "Yes\n";
    for(int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << '\n';
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
