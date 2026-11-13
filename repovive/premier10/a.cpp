#include <bits/stdc++.h>
using namespace std;
#define int long long
#define oo 8e18

void solve() {
    int n;
    cin >> n;
    int c = 0;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s[0] != s[1]) c++;
    }
    if (c & 1) {
        cout << -1 << '\n';
    } else {
        cout << c / 2 << '\n';
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
