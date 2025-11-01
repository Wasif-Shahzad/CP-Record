//
// c.cpp
// Created by Wasif on 10/11/25 at 09:53:54.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n + 1, 0), pref(n + 1), suff(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        pref[i] = a[i];
        if(i) pref[i] += pref[i - 1];
    }
    pref[0] = 0;
    suff[n] = a[n];
    for(int i = n - 1; i >= 0; i--) {
        suff[i] = a[i] + suff[i + 1];
    }
    auto f = [&] (int x) -> bool{
        return pref[x] <= suff[x];
    };
    int lo = -1, hi = n + 1;
    while(hi > lo + 1) {
        int mid = (hi + lo) / 2;
        if(f(mid)) lo = mid;
        else hi = mid;
    }
    cout << lo << " " << n - lo << '\n';
}