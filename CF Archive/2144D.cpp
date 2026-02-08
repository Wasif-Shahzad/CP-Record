//
// 2144D.cpp
// Created by wasifshahzad on 01/11/26 at 14:13:33.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    vector<int> f(2e5 + 1, 0);
    while(T--) {
        int n, y;
        cin >> n >> y;
        vector<int> a(n), b;
        for(int &i: a) {
            cin >> i;
            f[i]++;
            b.push_back(i);
        }
        sort(b.begin(), b.end());
        b.erase(unique(b.begin(), b.end()), b.end());
        vector<int> boundaries;
        for(int i: b) {
            for(int l = 1, r; l <= i; l = r + 1) {
                int v = (i + l - 1) / l;
                if(v == 1) {
                    r = i;
                } else {
                    r = (i - 1) / (v - 1);
                }
                boundaries.push_back(r + 1);
            }
        }
        #define all(x) x.begin(), x.end()
        sort(all(boundaries));
        boundaries.erase(unique(all(boundaries)), boundaries.end());
        int ans = LONG_LONG_MIN;
        for(int x: boundaries) {
            int cur = 0;
            for(int i: a) {
                int j = (i + x - 1) / x;
                if(f[j]) {
                    cur += j;
                    f[j]--;
                } else {
                    cur += j - y;
                }
            }
            for(int i: a) f[i] = 0;
            for(int i: a) f[i]++;
            ans = max(ans, cur);
        }
        cout << ans << '\n';
    }
}