//
// string_matching.cpp
// Created by Wasif on 11/26/25 at 10:30:44.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<int> p1, p2;
const int mod1 = 1e9+7, mod2 = 1e9+9;
random_device rd;
uniform_int_distribution<int> gen(50, 5e5);
int base = gen(rd);

struct Hash{
    vector<int> pref1, pref2;

    void build(string& s) {
        int n = s.size();
        pref1.resize(n + 1, 0);
        pref2.resize(n + 1, 0);

        for(int i = 1; i <= n; i++) {
            pref1[i] = ((pref1[i - 1] * base) % mod1 + (s[i - 1] - 'a' + 1)) % mod1;
            pref2[i] = ((pref2[i - 1] * base) % mod2 + (s[i - 1] - 'a' + 1)) % mod2;
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
    int n = s.size();

    p1 = p2 = {1};
    for(int i = 1; i <= n; i++) {
        p1.push_back((p1.back() * base) % mod1);
        p2.push_back((p2.back() * base) % mod2);
    }

    Hash hash;
    hash.build(s);

    for(int i = 0; i < n - 1; i++) {
        int j = n - i - 1;
        auto here = hash.get(0, i);
        auto there = hash.get(j, n - 1);
        if(here == there) cout << i + 1 << " ";
    }

}