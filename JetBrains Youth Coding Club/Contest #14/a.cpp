#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

void solve() {
    map<string, string> our = {
        {"red", "Reality"},
        {"yellow", "Mind"},
        {"orange", "Soul"},
        {"blue", "Space"},
        {"green", "Time"},
        {"purple", "Power"}
    };
    set<string> have;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        have.insert(s);
    }
    vector<string> ans;
    for(auto [u, v]: our) {
        if(have.count(u)) continue;
        ans.push_back(v);
    }
    cout << ans.size() << '\n';
    for(auto s: ans) cout << s << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
}

