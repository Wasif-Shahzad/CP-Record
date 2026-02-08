//
// c.cpp
// Created by wasifshahzad on 01/01/26 at 19:14:24.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> e, o;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            if(x & 1) o.push_back(x);
            else e.push_back(x);
        }
        sort(all(e));
        sort(all(o));
        if(!e.size()) {
            cout << *max_element(all(o)) << '\n';
            continue;
        }
        if(!o.size()) {
            cout << *max_element(all(e)) << '\n';
            continue;
        }
        int sm = e[0] + accumulate(all(o), 0ll) - (int)o.size() + 1;
        for(int i = 1; i < (int)e.size(); i++) sm += e[i];
        cout << sm << '\n';
    }
}