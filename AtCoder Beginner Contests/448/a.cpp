#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int &i: a) cin >> i;
    for(int i = 0; i < n; i++) {
        if(a[i] < x) {
            x = a[i];
            cout << 1 << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}
