//
// c.cpp
// Created by wasifshahzad on 12/22/25 at 17:04:13.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

const vector<int> dx = {1, 0, -1, 0, 0, 0};
const vector<int> dy = {0, 1, 0, -1, 0, 0};
const vector<int> dz = {0, 0, 0, 0, 1, -1};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int x, y, z;
        cin >> x >> y >> z;
        vector<vector<string>> g(z, vector<string>(x));
        for(int i = 0; i < z; i++) {
            for(int j = 0; j < x; j++) {
                cin >> g[i][j];
            }
        }
        int cnt = 0, cur = 0;
        vector<vector<vector<int>>> clr(z, vector<vector<int>>(x, vector<int>(y, -1))); 
        vector<vector<vector<int>>> vis(z, vector<vector<int>>(x, vector<int>(y, 0)));
        vector<vector<vector<int>>> has(z, vector<vector<int>>(x, vector<int>(y, 0)));
        auto dfs = [&] (int i, int j, int k, auto&& self) -> void {
            cnt++;
            vis[k][i][j] = 1;
            for(int n = 0; n < 6; n++) {
                int ni = i + dx[n], nj = j + dy[n], nk = k + dz[n];
                if(ni < 0 || nj < 0 || nk < 0 || ni >= x || nj >= y || nk >= z) continue;
                if(g[nk][ni][nj] == '#') continue;
                if(vis[nk][ni][nj]) continue;
                self(ni, nj, nk, self);
            }
        };
        auto fill = [&] (int i, int j, int k, auto&& self) -> void {
            clr[k][i][j] = cur;
            has[k][i][j] = cnt;
            for(int n = 0; n < 6; n++) {
                int ni = i + dx[n], nj = j + dy[n], nk = k + dz[n];
                if(ni < 0 || nj < 0 || nk < 0 || ni >= x || nj >= y || nk >= z) continue;
                if(g[nk][ni][nj] == '#') continue;
                if(clr[nk][ni][nj] != -1) continue;
                self(ni, nj, nk, self);
            }
        };
        for(int k = 0; k < z; k++) {
            for(int i = 0; i < x; i++) {
                for(int j = 0; j < y; j++) {
                    if(g[k][i][j] == '#') continue;
                    if(!vis[k][i][j]) {
                        cur++;
                        cnt = 0;
                        dfs(i, j, k, dfs);
                        fill(i, j, k, fill);
                    }
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < x; i++) {
            for(int j = 0; j < y; j++) {
                int here = 0;
                set<int> seen;
                for(int k = 0; k < z; k++) {
                    if(seen.count(clr[k][i][j])) continue;
                    if(g[k][i][j] == '#') continue;
                    here += has[k][i][j];
                    seen.insert(clr[k][i][j]);
                }
                ans = max(ans, here);
            }
        }
        cout << ans << '\n';
    }
}