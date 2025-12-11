//
// code.cpp
// Created by Wasif on 11/08/25 at 11:51:32.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

void solve() {
    int n, k;
    cin >> n >> k;
    map<int, int> has, extra;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if(has.count(x)) extra[x]++;
        else has[x] = 1;
    }
    int ans = has.size();
    vector<int> ops;
    for(auto [v, c]: extra) {
        for(int i = 1; i <= c; i++) {
            int st = v + c, need = i;
            while(has.count(st)) st++, need++;
            ops.push_back(need);
            has[st] = 1;
        }
    }
    sort(ops.begin(), ops.end());
    for(int i: ops) {
        if(i > k) break;
        k -= i;
        ans++;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    
}