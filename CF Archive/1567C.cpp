#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    string s1, s2;
    for(int i = 0; i < n; i++) {
        if (i & 1) s1 += s[i];
        else s2 += s[i];
    }
    if (n == 1) {
        cout << stoll(s) - 1 << '\n';
        return;
    }
    cout << (stoll(s1) + 1) * (stoll(s2) + 1) - 2 << '\n';
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
