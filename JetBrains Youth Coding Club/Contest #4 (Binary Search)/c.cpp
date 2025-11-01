//
// c.cpp
// Created by Wasif on 10/29/25 at 14:32:52.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> cnt(101, 0);
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }
    sort(cnt.rbegin(), cnt.rend());
    for(int i: cnt) {
        if(i == 0) break;
    }
    auto f = [&] (int x) -> bool{
        auto tmp = cnt;
        int p = n;
        while(p > 0) {
            if(tmp[0] < x) return false;
            tmp[0] -= x;
            sort(tmp.rbegin(), tmp.rend());
            p--;
        }
        return true;
    };
    int lo = -1, hi = 1;
    while(f(hi)) hi *= 2;
    while(hi > lo + 1) {
        int mid = (hi + lo) / 2;
        if(f(mid)) lo = mid;
        else hi = mid;
    }
    cout << lo << '\n';
}