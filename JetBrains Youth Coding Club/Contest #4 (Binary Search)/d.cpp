//
// d.cpp
// Created by Wasif on 10/29/25 at 14:39:46.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto f = [&] (int x) -> bool{
        int sm = 0, gr = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] > x) gr++;
            else if(a[i] < x) sm++;
        }
        if(gr > n / 2) return false;
        int change = sm - n / 2;
        vector<int> val;
        for(int i = 0; i < n; i++) {
            if(a[i] < x) val.push_back(a[i]);
        }
        sort(val.rbegin(), val.rend());
        int need = 0;
        for(int i = 0; i < change; i++) {
            need += x - val[i];
        }
        return need <= k;
    };
    sort(a.begin(), a.end());
    int med = a[n / 2];
    int lo = med, hi = med;
    while(f(hi)) hi *= 2;
    while(hi > lo + 1) {
        int mid = (hi + lo) / 2;
        if(f(mid)) lo = mid;
        else hi = mid;
    }
    cout << lo << '\n';
}