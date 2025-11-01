//
// g.cpp
// Created by Wasif on 10/29/25 at 16:18:08.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define ar array<int, 3>

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, h;
    cin >> n >> k >> h;
    vector<pair<int, int>> a(n);
    vector<ar> b(n);
    for(int i = 0; i < n; i++)
        cin >> a[i].first;
    for(int i = 0; i < n; i++) 
        cin >> a[i].second;

    for(int i = 0; i < n; i++) {
        b[i] = {a[i].first, a[i].second, i};
    }

    sort(b.begin(),b.end(), [&] (ar x, ar y) {
        if(x[0] != y[0]) return x[0] > y[0];
        if(x[1] != y[1]) return x[1] > y[1];
        return x[2] < y[2];
    });

    
    vector<int> seq;
    const long double eps = 1e-12;
    auto f = [&] (long double x) -> bool{
        seq = {};
        int taken = 0, m = k;
        for(auto [w, v, i]: b) {
            long double time = (m * h * 1.0L) / v;
            if(time > x + eps) continue;
            seq.push_back(i);
            taken++;
            if(taken == k) return true;
            m--;
        }
        return false;
    };
    long double lo = 0, hi = 1;
    while(!f(hi)) hi *= 2;
    for(int i = 0; i < 90; i++) {
        long double mid = (hi + lo) / 2;
        if(f(mid)) hi = mid;
        else lo = mid;
    }
    f(hi);
    reverse(seq.begin(), seq.end());
    for(int i: seq) cout << i + 1 << " ";
    cout << '\n';
}