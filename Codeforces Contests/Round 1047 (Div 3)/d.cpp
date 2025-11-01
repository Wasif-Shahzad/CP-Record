#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        map<int, int> f;
        vector<vector<int>> ind(n + 1);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            f[a[i]]++;
            ind[a[i]].push_back(i);
        }        
        bool bad = false;
        for(auto [v, c]: f) {
            if(c % v != 0) {
                bad = true;
                break;
            }
        }
        if(bad) {
            cout << -1 << '\n';
            continue;
        }
        vector<int> ans(n);
        int cur = 1;
        for(int i: ind[1]) {
            ans[i] = cur++;
        }
        for(int i = 2; i <= n; i++) {
            for(int j = 0; j < ind[i].size(); j++) {
                if(j % i == 0) cur++;
                ans[ind[i][j]] = cur;
            }
        }
        for(int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << '\n';
    }
}