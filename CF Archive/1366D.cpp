//
// 1366D.cpp
// Created by Wasif on 10/12/25 at 12:21:44.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int N = 1e7+5;
int spf[N];

vector<int> pf(int x) {
    vector<int> res;
    while(x != 1) {
        res.push_back(spf[x]);
        int cur = spf[x];
        while(x % cur == 0) x /= cur;
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    iota(spf, spf + N, 0);
    for(int i = 2; i * i < N; i++) {
        if(spf[i] == i) {
            for(int j = i * i; j < N; j += i) {
                if(spf[j] == j) {
                    spf[j] = i;
                }
            }
        }
    }

    int n;
    cin >> n;
    vector<int> a(n);
    vector<pair<int, int>> ans(n, {-1, -1});
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        auto fact = pf(a[i]);
        if(fact.size() > 1) {
            ans[i].first = fact[0];
            ans[i].second = 1;
            for(int j = 1; j < fact.size(); j++) ans[i].second *= fact[j];
        }
    }
    for(int i = 0; i < n; i++) {
        cout << ans[i].first << " \n"[i + 1 == n];
    }
    for(int i = 0; i < n; i++) {
        cout << ans[i].second << " \n"[i + 1 == n];
    }
}