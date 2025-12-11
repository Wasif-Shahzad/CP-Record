//
// c.cpp
// Created by Wasif on 11/28/25 at 19:31:08.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

void solve() {
    int n, k;
    cin >> n >> k;
    multiset<int> q, r;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        q.insert(x);
    }
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        r.insert(x);
    }

    // small q, large r as early as possible
    int cnt = 0;
    while(q.size() && r.size()) {
        int qt = *q.begin();
        int rt = *r.rbegin();
        // d + x <= d + d
        int y = rt + 1;
        int x = qt * y + rt;
        if(x <= k && x / y == qt && x % y == rt) {
            cnt++;
            q.erase(q.find(qt));
        }
        r.erase(r.find(rt));
    }
    cout << cnt << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) solve();
    
}