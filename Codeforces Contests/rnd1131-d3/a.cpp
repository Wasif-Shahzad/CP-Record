#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    string p;
    cin >> p;
    vector<int> f1(26, 0), f2(26, 0);
    for(auto i: s) {
        f1[i - 'a']++;
    }
    for(auto i: p) {
        f1[i - 'a']--;
    }
    bool ans = f1[18] == 1 && f1[8] == 1 && f1[23] == 1;
    for(int i = 0; i < 26; i++) {
        if (i == 18 || i == 8 || i == 23) continue;
        if (f1[i] != 0) ans = false;
    }
    cout << (ans ? "Yes" : "No") << '\n';
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
