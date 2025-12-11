//
// word_combinations.cpp
// Created by Wasif on 11/26/25 at 09:44:04.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<int> p1, p2;
const int mod1 = 1000000007, mod2 = 1000000009;
random_device rd;
uniform_int_distribution<int> gen(50, 1e6);
int base = gen(rd);

struct Hash{
    vector<int> pref1, pref2;

    void build(string& s) {
        int n = s.size();
        pref1.resize(n + 1, 0);
        pref2.resize(n + 1, 0);

        for(int i = 1; i <= n; i++) {
            pref1[i] = (pref1[i - 1] * base % mod1 + (s[i - 1] - 'a' + 1)) % mod1;
            pref2[i] = (pref2[i - 1] * base % mod2 + (s[i - 1] - 'a' + 1)) % mod2;
        }
    }

    pair<int, int> get(int l, int r) {
        int len = r - l + 1;
        int first = ((pref1[r + 1] - (pref1[l] * p1[len]) % mod1) + mod1) % mod1;
        int second = ((pref2[r + 1] - (pref2[l] * p2[len]) % mod2) + mod2) % mod2;
        return {first, second};
    }
};  

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int k;
    cin >> k;
    vector<string> t(k);
    int mx = s.size();
    for(int i = 0; i < k; i++) {
        cin >> t[i];
        mx = max(mx, (int)t[i].size());
    }

    p1.push_back(1);
    p2.push_back(1);
    for(int i = 1; i <= mx; i++) {
        p1.push_back((p1.back() * base) % mod1);
        p2.push_back((p2.back() * base) % mod2);
    }   

    Hash hash;
    hash.build(s);

    vector<pair<int, int>> h(k);
    vector<vector<pair<int, int>>> f(s.size() + 1);

    for(int i = 0; i < k; i++) {
        if(t[i].size() > s.size()) continue;
        Hash tmp;
        tmp.build(t[i]);
        int m = t[i].size();
        f[m].push_back({tmp.pref1[m], tmp.pref2[m]});
    }

    for(int i = 0; i <= s.size(); i++) {
        if(f[i].size()) {
            sort(f[i].begin(), f[i].end());
            f[i].erase(unique(f[i].begin(), f[i].end()), f[i].end());
        }
    }

    int n = s.size();
    vector<vector<pair<int, int>>> pre(n, vector<pair<int, int>>(n));

    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            pre[i][j] = hash.get(i, j);
        }
    }

    vector<int> dp(n + 1, 0);
    dp[n] = 1;


    for(int i = n - 1; i >= 0; i--) {
        for(int len = 1; i + len <= n; len++) {
            int r = i + len - 1;
            auto our = pre[i][r];

            if(binary_search(f[len].begin(), f[len].end(), our)) {
                dp[i] += dp[r + 1];
                dp[i] %= mod1;
            }
        }
    }
    cout << dp[0] << '\n';
}