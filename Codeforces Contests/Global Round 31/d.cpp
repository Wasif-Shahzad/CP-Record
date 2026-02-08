//
// d.cpp
// Created by wasifshahzad on 12/19/25 at 20:20:27.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;
#define BAD -10000000000

int find(pair<int, int> f, pair<int, int> s) {
    if(f.second <= s.first || s.second <= f.first) return BAD;
    if(s.first < f.first) return f.first;
    return s.first;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<int> l(n), r(n);
        l[0] = a[0] - (a[1] - a[0]);
        r[0] = a[1];
        l[n - 1] = a[n - 2];
        r[n - 1] = a[n - 1] + (a[n - 1] - a[n - 2]);
        for(int i = 1; i + 1 < n; i++) {
            int d = min(a[i] - a[i - 1], a[i + 1] - a[i]);
            l[i] = a[i] - d;
            r[i] = a[i] + d;
        }
        int mn = 0;
        int ans = 0;
        for(int i = 0; i + 1 < n; i++) {
            pair<int, int> f = {a[i] + mn, r[i]};
            pair<int, int> s = {l[i + 1], a[i + 1]};
            int inter = find(f, s);
            if(inter == BAD) {
                mn = 0;
                continue;
            }
            ans++;
            mn = a[i + 1] - r[i];
        }
        cout << ans << '\n';
    }
}