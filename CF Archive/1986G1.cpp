//
// 1986G1.cpp
// Created by wasifshahzad on 12/15/25 at 21:20:18.
//

#include <bits/stdc++.h>
using namespace std;
// #define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;
const int N = 5e5+1;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<vector<int>> divs(N);
    for(int i = 1; i < N; i++) {
        for(int j = i; j < N; j += i) {
            divs[j].push_back(i);
        }
    }
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> a(n + 1), b(n + 1);
        vector<vector<int>> has_a(n + 1), has_b(n + 1);
        for(int i = 1; i <= n; i++) {
            int p; cin >> p;
            a[i] = p / __gcd(p, i);
            b[i] = i / __gcd(p, i);
            has_a[a[i]].push_back(b[i]);
            has_b[b[i]].push_back(a[i]);
        }
        long long ans = 0;
        vector<int> cnt(n + 1, 0);
        for(int B = 1; B <= n; B++) {
            for(int j = B; j <= n; j += B) {
                for(int x: has_a[j]) {
                    cnt[x]++;
                }
            }
            for(int j: has_b[B]) {
                for(int k: divs[j]) {
                    ans += 1ll * cnt[k];
                }
            }
            for(int j = B; j <= n; j += B) {
                for(int x: has_a[j]) {
                    cnt[x] = 0;
                }
            }
        }
        for(int i = 1; i <= n; i++) {
            ans -= (b[i] == 1);
        }
        cout << ans / 2ll << '\n';
    }
}