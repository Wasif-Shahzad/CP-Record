#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    for(char x = 'z'; x > 'a'; x--) {
        string t = s;
        reverse(t.begin(), t.end());
        if (t == s) break;
        bool needed = false;
        for(int i = 0; i < n; i++) {
            if (s[i] != s[n - i - 1] && s[i] == x) {
                needed = true;
                break;
            }
        }
        if (!needed) continue;
        int op = 0;
        for(int i = 0; i < n; i++) {
            if (s[i] == x) s[i]--, op = 1;
        }
        ans += op;
    }
    cout << ans << '\n';
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
