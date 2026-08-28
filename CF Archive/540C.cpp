#include <bits/stdc++.h>
using namespace std;

int main() {
    /*
     * we get disconnectivity if ice breaks
     * if we reach the cell above our target then 4 cases
     * (x, x) W, (., X) W, (X, X) W, (X, .) need one of the other neighbours to be intact for win
     * if we are cracked then reaching any neighbour works
     * otherwise, we reach our target first. if we reach without touching top then win.
     * otherwise, if top was cracked then need one of the other neighbours to be intact
     * if top was not cracked its a win
     * checking that visitability is also tough
     */
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for(int i = 0; i < n; i++) cin >> g[i];
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    r1--, c1--, r2--, c2--;
    vector<vector<int>> vis(n, vector<int>(m, 0));
    const vector<int> dx = {1, 0, -1, 0};
    const vector<int> dy = {0, 1, 0, -1};
    auto bfs = [&] (int x, int y, vector<vector<int>>& vis, bool dbg=false) -> void {
        queue<pair<int, int>> q;
        q.push({x, y});
        vis[x][y] = 1;
        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            if (dbg) cerr << "(" << r << ", " << c << ")" << '\n';
            if(g[r][c] == 'X' && (r != x || c != y)) {
                continue;
            }
            for(int i = 0; i < 4; i++) {
                int nr = r + dx[i], nc = c + dy[i];
                if(nr >= n || nc >= m || nr < 0 || nc < 0) continue;
                if (vis[nr][nc]) continue;
                q.push({nr, nc});
                vis[nr][nc] = 1;
            }
        }
    };
    bfs(r1, c1, vis);
    if(r1 == r2 && c1 == c2) {
        int cnt = 0;
        for(int i = 0; i < 4; i++) {
            int r = r2 + dx[i], c = c2 + dy[i];
            if(r < 0 || c < 0 || r >= n || c >= m) continue;
            cnt += g[r][c] == '.';
        }
        cout << (cnt >= 1 ? "YES" : "NO") << '\n';
        return 0;
    }
    if (g[r2][c2] == 'X' && vis[r2][c2]) {
        cout << "YES\n";
        return 0;
    }
    if(g[r2][c2] == '.' && vis[r2][c2]) {
        int cnt = 0;
        for(int i = 0; i < 4; i++) {
            int r = r2 + dx[i], c = c2 + dy[i];
            if(r < 0 || c < 0 || r >= n || c >= m) continue;
            cnt += g[r][c] == '.';
        }
        int threshold = 2;
        if (abs(r1 - r2) + abs(c1 - c2) == 1) threshold = 1;
        cout << (cnt >= threshold ? "YES" : "NO") << '\n';
        return 0;
    }
    cout << "NO\n";
}
