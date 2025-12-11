//
// c.cpp
// Created by Wasif on 12/05/25 at 19:39:44.
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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        map<int, int> has;
        for(int i = 0; i< n; i++) {
            cin >> a[i];
            has[a[i]] = 1;
        }
        auto c = a;
        sort(c.begin(), c.end());
        c.erase(unique(c.begin(), c.end()), c.end());
        map<int, int> done;
        vector<int> b;
        bool good = true;
        for(int i = 0; i < n; i++) {
            if(done[c[i]]) continue;
            int m = k / c[i];
            if(m > n) {
                good = false;
                break;
            }
            for(int j = 2; j <= m; j++) {
                if(!has[c[i] * j]) {
                    good = false;
                    break;
                }
            }
            if(!good) break;
            b.push_back(c[i]);
            for(int j = 1; j <= m; j++) {
                done[j * c[i]] = 1;
            }
        }
        if(good) {
            cout << b.size() << '\n';
            for(int x: b) cout << x << " ";
            cout << '\n';
        } else cout << -1 << '\n';
    }
}