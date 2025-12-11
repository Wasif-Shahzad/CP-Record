//
// d.cpp
// Created by Wasif on 11/06/25 at 21:09:09.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

void solve(){
    int n, k;
    cin >> n >> k;
    string s, t;
    cin >> s >> t;
    if(s[0] != t[0]) {
        cout << -1 << '\n';
        return;
    }
    vector<vector<int>> ind(26);
    for(int i = 0; i < n; i++) {
        ind[s[i] - 'a'].push_back(i);
    }
    int j = n - 1, ops = 0;
    for(int i = n - 1; i >= 0; i--) {
        int k_ = t[i] - 'a';
        while(ind[k_].size() && ind[k_].back() > j) ind[k_].pop_back();
        while(ind[k_].size() && ind[k_].back() > i) ind[k_].pop_back();
        if(!ind[k_].size()) {
            cout << -1 << '\n';
            return;
        }
        ops = max(ops, i - ind[k_].back());
        j = ind[k_].back();
    }
    if(ops > k) {
        cout << -1 << '\n';
        return;
    }
    vector<string> ans;
    while(s != t) {
        ind.assign(26, {});
        for(int i = 0; i < n; i++) {
            ind[s[i] - 'a'].push_back(i);
        }
        j = n - 1;
        for(int i = n - 1; i >= 0; i--) {
            int k_ = t[i] - 'a';
            while(ind[k_].size() && ind[k_].back() > j) ind[k_].pop_back();
            while(ind[k_].size() && ind[k_].back() > i) ind[k_].pop_back();
            if(!ind[k_].size()) {
                cout << -1 << '\n';
                return;
            }
            j = ind[k_].back();
            if(i == j) continue;
            if(j + 1 < n) s[j + 1] = s[j];
        }
        ans.push_back(s);
    }
    cout << ops << '\n';
    for(auto i: ans) cout << i << '\n';
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