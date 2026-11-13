#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    vector<int> b;
    set<int> a;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (a.count(x)) {
            b.push_back(x);
        } else {
            a.insert(x);
        }
    }
    sort(b.rbegin(), b.rend());
    int ans = a.size() + b.size();
    for(int i = 1; i < b.size(); i++) {
        if (b[i] == b[i - 1]) ans--;
    }
    cout << ans << '\n';
    for(int i: a) cout << i << " ";
    for(int i: b) cout << i << " ";
    cout << '\n';
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
