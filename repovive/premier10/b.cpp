#include <bits/stdc++.h>
using namespace std;
#define int long long
#define oo 8e18

void solve() {
    // at the end we will have someone with zero so we need at least one bi with 0
    // pot i can only be watered in the first k - b[i] times.
    // if a[i] >= b[i] then we must water it on k - b[i] and then not water it
    // if a[i] < b[i], first we go to b[i] and then do the above thing on it
    // if a[i] < b[i] we need k - b[i] >= b[i] - a[i]
    // 312411
    int n, k;
    cin >> n >> k;
    map<int, int> f;
    bool bad = false, zr = false;
    vector<int> a(n), b(n);
    for(int &i: a) cin >> i;
    for(int &i: b) cin >> i;
    for(int i = 0; i < n; i++) {
        int A = a[i], B = b[i];
        if (B == 0) zr = true;
        if (B - A == k) continue;
        if (k - B <= 0) {
            // cout << i << '\n';
            bad = true;
            break;
        }
        if (f.count(k - B)) {
            // cout << i << '\n';
            bad = true;
            break;
        }
        f[k - B] = 1;
    }
    if (!zr) bad = true;
    if (bad) {
        cout << "NO\n";
        return;
    }
    cout << "Yes\n";
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
