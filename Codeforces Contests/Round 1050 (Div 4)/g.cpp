//
// g.cpp
// Created by Wasif on 09/13/25 at 19:49:40.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<int> spf(2e5 + 5);

vector<pair<int, int>> fact(int x) {
    vector<pair<int, int>> have;
    while(x != 1) {
        int cnt = 0;
        int cur = x, p = spf[x];
        while(cur % spf[x] == 0) {
            cnt++;
            cur /= spf[x];
        }
        have.push_back({p, cnt});
        x = cur;
    }
    return have;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    iota(spf.begin(), spf.end(), 0);
    for(int i = 2; i * i <= 2e5; i++) {
        if(spf[i] == i) {
            for(int j = i * i; j <= 2e5; j += i) {
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        map<pair<int, int>, int> mp;
        multiset<int> s;
        for(int i = 0; i < n; i++) {
            auto cur = fact(a[i]);
            for(auto [u, v]: cur) {
                for(int i = 1; i <= v; i++) {
                    if(mp.count({u, i})) {
                        s.erase(s.find(mp[{u, i}]));
                    }
                    mp[{u, i}]++;
                    s.insert(mp[{u, i}]);
                }
            }   
            auto it = s.upper_bound(i);
            if(it == s.begin()) {
                cout << 0 << ' ';
            } else {
                it--;
                cout << *it << " ";
            }
        }
        cout << '\n';
    }
}