#include <bits/stdc++.h>
using namespace std;
#define int long long

bool done = false;
int n, m;
vector<int> dx = {1, 0, -1, 0};
vector<int> dy = {0, 1, 0, -1};
vector<char> dir = {'U', 'L', 'D', 'R'};
vector<string> a;
vector<vector<int>> vis;
vector<vector<pair<int, int>>> par;
int need, have;

void dfs(int i, int j) {
    queue<pair<int, int>> q;
    q.push({i, j});
    vis[i][j] = 1;
    while(q.size()) {
        auto [i, j] = q.front();
        a[i][j] = 'X';
        have++;
        q.pop();
        for(int k = 0; k < 4; k++) {
            int ni = i + dx[k], nj = j + dy[k];
            if(ni < 0 || nj < 0 || ni >= n || nj >= m) continue;
            if(vis[ni][nj]) continue;
            if(a[ni][nj] == 'w') continue;
            par[ni][nj] = {i, j};
            q.push({ni, nj});
            vis[ni][nj] = 1;
        }
    }
}

void solve() {
    while(cin >> n >> m) {
        a.resize(n);
        vis.assign(n, vector<int>(m, 0));
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int x, y; cin >> x >> y;
        dfs(x, y);
        int s = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                s += vis[i][j];
            }
        }
        cout << s << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // int t = 1;
    // // cin >> t;
    // while(t--) {
    //     solve();
    // }
    solve();
}
