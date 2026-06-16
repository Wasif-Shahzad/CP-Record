//
// 1360G.cpp
// Created by wasifshahzad on 04/10/26 at 11:21:43.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

/*
[1, 1, 0, 0, 0]
[1, 1, 0, 0, 0]
[0, 0, 1, 1, 0] => 0
[0, 0, 1, 1, 0] => 0
[0, 0, 0, 0, 1] => 1
*/ 

void solve() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;
    vector<vector<int>> ans(n, vector<int>(m, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < a; j++) ans[i][j] = 1;
    }
    vector<int> extra(n, 0), slots(n, m - a);
    int bg = 0;
    for(int j = 0; j < m; j++) {
        // greedily right shift this column
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(ans[i][j]) {
                cnt++;
            }
        }
        if(cnt > b) {
            for(int i = n - 1; i >= 0; i--) {
                if(cnt == b) break;
                if(ans[i][j] && slots[i]) {
                    ans[i][j] = 0;
                    extra[i]++;
                    cnt--;
                    slots[i]--;
                }
            }
        } else if(cnt < b) {
            int tot = 0;
            for(;tot < b; tot++, bg = (bg + 1) % b) {
                for(int k = bg; k < n; k += b) {
                    if(ans[k][j]) continue;
                    if(extra[k]) {
                        extra[k]--;
                        cnt++;
                        ans[k][j] = 1;
                    }
                    if(cnt == b) break;
                }   
                if(cnt == b) {
                    bg = (bg + 1) % b;
                    break;
                }
            }
        }
        if(cnt != b) {
            cout << "NO\n";
            return;
        }
    }
    if(accumulate(all(extra), 0ll) > 0) {
        cout << "NO\n";
        return;
    }
    for(int i = 0; i < n; i++) {
        int cur = 0;
        for(int j = 0; j < m; j++) cur += ans[i][j];
        if(cur != a) {
            cout << "NO\n";
            return;
        }
    }
    for(int j = 0; j < m ;j++) {
        int cur = 0;
        for(int i = 0; i < n; i++) cur += ans[i][j];
        if(cur != b) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) cout << ans[i][j];
        cout << '\n';
    }
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