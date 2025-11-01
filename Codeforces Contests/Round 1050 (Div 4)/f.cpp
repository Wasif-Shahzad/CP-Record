//
// f.cpp
// Created by Wasif on 09/13/25 at 20:02:52.
//

#include <bits/stdc++.h>
using namespace std;
// #define int long long
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
        vector<deque<int>> a(n);
        int mx = 0;
        for(int i = 0; i < n; i++) {
            int k;
            cin >> k;
            mx = max(mx, k);
            a[i].resize(k);
            for(int j = 0; j < k; j++) {
                cin >> a[i][j];
            }
        }
        vector<int> mn(mx, 1e9);
        for(int j = 0; j < mx; j++) {
            for(int i = 0; i < n; i++) {
                if(a[i].size() > j) mn[j] = min(mn[j], a[i][j]);
            }
        }
        int i = 0;
        while(i < mx) {
            deque<int> bst;
            for(int j = 0; j < n; j++) {
                if(bst.empty() && a[j].size()) bst = a[j];
                else if(a[j].size()) bst = min(bst, a[j]);
            }
            for(int j: bst) cout << j << " ";
            i += bst.size();
            for(int j = 0; j < n; j++) {
                if(a[j].size() <= bst.size()) a[j] = {};
                else {
                    if(a[j][bst.size()] != mn[i]) a[j] = {};
                    else {
                        for(int k = 0; k < bst.size(); k++) a[j].pop_front();
                    }
                }
            }
        }
        cout << '\n';
    }
}