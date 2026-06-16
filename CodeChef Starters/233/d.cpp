//
// d.cpp
// Created by wasifshahzad on 04/08/26 at 20:36:10.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = s[n - 1] + s;
    s += s[1];
    vector<int> bad(n + 2, 0);
    for(int i = 1; i <= n; i++) {
        if(s[i] != s[i - 1] && s[i] != s[i + 1]) bad[i] = 1;
    }
    if(accumulate(all(bad), 0ll) == n) {
        cout << -1 << '\n';
        return;
    }
    int ans = 0, cur = 0;
    for(int i = 1; i <= n; i++) {
        if(bad[i] == 0) {
            ans = max(ans, (cur + 1) / 2);
            cur = 0;
        } else {
            cur++;
        }
    }
    ans = max(ans, (cur + 1) / 2);
    if(bad[1]) {
        cur = 0;
        int j = 1;
        for(int i = 1; i <= n; i++) {
            if(bad[i]) cur++, j++;
            else break;
        }
        for(int i = n; i >= j; i--) {
            if(bad[i]) cur++;
            else break;
        }
        ans = max(ans, (cur + 1) / 2);
    }
    cout << ans + 1 << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}