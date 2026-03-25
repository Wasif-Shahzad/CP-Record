#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

void solve() {
    string s, t;
    cin >> s >> t;
    map<char, char> have;
    int n = s.size();
    for(int i = 0; i < n; i++) {
        if(have.count(s[i])) continue;
        have[s[i]] = t[i];
        have[t[i]] = s[i];
    }
    string res;
    for(int i = 0; i < n; i++) {
        res += have[t[i]];
    }
    if(res != s) {
        cout << -1 << '\n';
    } else {
        vector<int> vis(26, 0);
        vector<pair<char, char>> ans;
        for(int i = 0; i < n; i++) {
            if(s[i] == t[i]) continue;
            if(vis[s[i] - 'a']) continue;
            vis[s[i] - 'a'] = vis[t[i] - 'a'] = 1;
            ans.push_back({s[i], t[i]});
        }
        cout << ans.size() << '\n';
        for(auto [u, v]: ans) cout << u << " " << v << '\n';
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
