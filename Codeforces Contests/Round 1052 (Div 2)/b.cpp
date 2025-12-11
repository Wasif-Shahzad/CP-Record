//
// b.cpp
// Created by Wasif on 12/08/25 at 20:50:33.
//

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
        int n, m;
        cin >> n >> m;
        vector<vector<int>> a(n);
        vector<int> freq(m + 1, 0);
        for(int i = 0; i < n; i++) {
            int l; cin >> l;
            a[i].resize(l);
            for(int j = 0; j < l; j++) {
                cin >> a[i][j];
                freq[a[i][j]]++;
            }
        }
        bool good = true;
        for(int i = 1; i <= m; i++) {
            if(freq[i] == 0) {
                good = false;
                break;
            }
        }
        if(!good) {
            cout << "No\n";
            continue;
        }
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            bool good = true;
            for(int j = 0; j < a[i].size(); j++) {
                if(freq[a[i][j]] == 1) {
                    good = false;
                    break;
                }
            }
            if(good) cnt++;
        }
        cout << (cnt >= 2 ? "Yes" : "No") << '\n';
    }
}