//
// ceoi_palindromic_partitions.cpp
// Created by Wasif on 11/13/25 at 20:31:47.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

struct Hash {
    int mod1 = 1e9+9, mod2 = 1e9+7;
    int base;
    vector<int> p1, p2;
    vector<int> pref1, pref2;

    Hash(int b) : base(b) {}

    void build(string& s) {
        int n = s.size();
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
            pref1[i + 1] = ((pref1[i] * base) % mod1 + (s[i] - 'a' + 1) % mod1) % mod1;
            pref2[i + 1] = ((pref2[i] * base) % mod2 + (s[i] - 'a' + 1) % mod2) % mod2;
        }
    }

    pair<int, int> get(int l, int r) {
        int len = r - l + 1;
        int first = ((pref1[r + 1] - (pref1[l] * p1[len]) % mod1 + mod1)) % mod1;
        int second = ((pref2[r + 1] - (pref2[l] * p2[len]) % mod2 + mod2)) % mod2;
        return {first, second};
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> distrib(50, 1e5);
        int base = distrib(gen);
        Hash hash(base);
        hash.build(s);
        int n = s.size();
        int ans = 0;
        int l = 0, r = n - 1, i = 0, j = n - 1;
        while(i <= j) {
            if(i == j) {
                ans++;
                break;
            }
            auto h1 = hash.get(l, i);
            auto h2 = hash.get(j, r);
            if(h1 == h2) {
                l = i + 1;
                r = j - 1;
                ans += 2;
            }
            i++, j--;
        }
        if(l < r && i != j) ans++;
        cout << ans << '\n';
    }
}