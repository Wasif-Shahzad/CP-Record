#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

void solve() {
    int h, m, s, t1, t2;
    cin >> h >> m >> s >> t1 >> t2;
    h = h * 5 % 60, t1 = t1 * 5 % 60, t2 = t2 * 5 % 60;;
    vector<int> vis(60, 0);
    auto dfs = [&] (int i, auto&& self) -> void {
        if(i == h || i == m || i == s) return;
        if(vis[i]) return;
        vis[i] = 1;
        self((i + 1) % 60, self);
        self(((i - 1) % 60 + 60) % 60, self);
    };
    auto dfs2 = [&] (int i, auto&& self) -> void {
        if(vis[i]) return;
        vis[i] = 1;
        if(i == h || i == m || i == s) return;
        self((i + 1) % 60, self);
        self(((i - 1) % 60 + 60) % 60, self);
    };
    if(t1 == h || t1 == m || t1 == s) {
        {
            vis[t1] = 1;
            dfs((t1 + 1) % 60, dfs);
            if(vis[t2]) {
                cout << "YES\n";
                return;
            }
        }
        {
            vis.assign(60, 0);
            vis[t1] = 1;
            dfs(((t1 - 1) % 60 + 60) % 60, dfs);
            if(vis[t2]) {
                cout << "YES\n";
                return;
            }
        }
    } else {
        dfs2(t1, dfs2);
        if(vis[t2]) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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
