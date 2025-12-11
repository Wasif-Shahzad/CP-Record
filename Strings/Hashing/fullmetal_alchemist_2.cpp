//
// fullmetal_alchemist_2.cpp
// Created by Wasif on 11/16/25 at 10:33:12.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

random_device rd;
mt19937 gen(rd());
uniform_int_distribution<int> distrib(50, 1e6);
int base = distrib(gen);

struct Hash {
    int mod1 = 1e9+7, mod2 = 1e9+9;
    vector<int> p1, p2, pref1, pref2;

    void build(string& s) {
        int n = s.size();
        p1 = {};
        p2 = {};
        p1.push_back(1);
        p2.push_back(1);
        while(p1.size() <= n) {
            p1.push_back((p1.back() * base) % mod1);
            p2.push_back((p2.back() * base) % mod2);
        }
        pref1.resize(n + 1);
        pref2.resize(n + 1);
        pref1[0] = pref2[0] = 0;
        for(int i = 0; i < n; i++) {
            pref1[i + 1] = ((pref1[i] * base) % mod1 + (s[i] - 'a' + 1)) % mod1;
            pref2[i + 1] = ((pref2[i] * base) % mod2 + (s[i] - 'a' + 1)) % mod2;
        }
    }

    pair<int, int> get(int l, int r) {
        int len = r - l + 1;
        int h1 = ((pref1[r + 1] - (pref1[l] * p1[len]) % mod1) + mod1) % mod1;
        int h2 = ((pref2[r + 1] - (pref2[l] * p2[len]) % mod2) + mod2) % mod2;
        return {h1 % mod1, h2 % mod2};
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> a(n);
    vector<Hash> hashes(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        hashes[i].build(a[i]);
    }

    auto is_substr = [&] (int i, int j) -> bool {
        if(a[j].size() > a[i].size()) return false;
        int n = a[i].size(), m = a[j].size();
        auto h2 = hashes[j].get(0, m - 1);
        for(int ii = 0; ii + m <= n; ii++) {
            int jj = ii + m - 1;
            auto h1 = hashes[i].get(ii, jj);
            if(h1 == h2) return true;
        }
        return false;
    };

    vector<int> rm(n, 0);
    for(int i = 0; i < n; i++) {
        if(rm[i]) continue;
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            if(is_substr(i, j)) {
                rm[j] = 1;
            }
        }
    }
    vector<string> b;
    for(int i = 0; i < n; i++) {
        if(!rm[i]) b.push_back(a[i]);
    }
    n = b.size();
    a = b;
    hashes.resize(n);
    for(int i = 0; i < n; i++) {
        hashes[i].build(a[i]);
    }
    // [mask][last picked][new addition]
    vector<vector<int>> match(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            int r = min(a[i].size(), a[j].size());
            int m = a[i].size();
            for(int k = 1; k <= r; k++) {
                int l = m - k;
                auto h1 = hashes[i].get(l, m - 1);
                auto h2 = hashes[j].get(0, k - 1);
                if(h1 == h2) match[i][j] = k;
            }
        }
    }
    vector<vector<int>> dp(1 << n, vector<int>(n + 1, 1e9));
    dp[0][n] = 0;
    for(int mask = 1; mask < (1 << n); mask++) {
        if(__builtin_popcount(mask) == 1) {
            int j = 63 - __builtin_clzll(mask);
            dp[mask][n] = a[j].size();
            continue;
        }
        for(int i = 0; i < n; i++) {
            if((1 << i) & mask) {
                for(int j = 0; j < n; j++) {
                    if(i == j) continue;
                    if((1 << j) & mask) {
                        int here = a[j].size() - match[i][j];
                        int new_mask = mask ^ (1 << j);
                        if(__builtin_popcountll(new_mask) == 1) {
                            dp[mask][j] = min(dp[mask][j], here + (int)a[i].size());
                        } else {
                            dp[mask][j] = min(dp[mask][j], here + dp[new_mask][i]);
                        }
                    }
                }
            }
        }
    }
    cout << *min_element(dp[(1 << n) - 1].begin(), dp[(1 << n) - 1].end()) << '\n';
}