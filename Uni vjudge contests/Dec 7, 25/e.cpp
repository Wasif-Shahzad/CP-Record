//
// e.cpp
// Created by Wasif on 12/07/25 at 21:47:09.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        int mx = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            mx = max(mx, a[i]);
        }
        priority_queue<int> pq;
        for(int i = 0; i < n; i++) {
            if(a[i] != mx) pq.push(mx - a[i]);
        }
        int ans = 0;
        while(pq.size()) {
            ans++;
            int k = pq.size();
            vector<int> tmp;
            for(int i = 0; i < min(m, k); i++) {
                int j = pq.top();
                pq.pop();
                if(j != 1) tmp.push_back(j - 1);
            }
            for(int i: tmp) pq.push(i);
        }
        cout << ans << '\n';
    }
}