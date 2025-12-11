//
// finding_periods.cpp
// Created by Wasif on 11/08/25 at 11:29:05.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

struct Hash{
    vector<int> p1, p2;
    vector<int> pref1, pref2;
    int n, mod1 = 1e9+7, mod2 = 1e9+9, b;

    Hash(int base) : b(base) {}

    void build(string& s) {
        n = s.size();
        p1.push_back(1);
        p2.push_back(1);
        while(p1.size() <= n) {
            p1.push_back((p1.back() * b) % mod1);
            p2.push_back((p2.back() * b) % mod2);
        }
        pref1.resize(n + 1, 0);
        pref2.resize(n + 1, 0);
        for(int i = 0; i < n; i++) {
            pref1[i + 1] = ((pref1[i] * b) % mod1 + (s[i] - 'a' + 1)) % mod1;
            pref2[i + 1] = ((pref2[i] * b) % mod2 + (s[i] - 'a' + 1)) % mod2;
        }
    }

    pair<int, int> get(int l, int r) {
        if(l > r) return {0, 0};
        int len = r - l + 1;
        int h1 = (pref1[r + 1] - (pref1[l] * p1[len]) % mod1 + mod1) % mod1;
        int h2 = (pref2[r + 1] - (pref2[l] * p2[len]) % mod2 + mod2) % mod2;
        return {h1, h2};
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(50, 1e5);
    int base = distrib(gen);
    Hash hash(base);
    hash.build(s);

    set<char> tmp(s.begin(), s.end());
    if(tmp.size() == 1) {
        for(int i = 1; i <= s.size(); i++) cout << i << " ";
        cout << '\n';
        return 0;
    }

    int n = s.size();
    vector<int> ans;
    for(int i = 1; i <= n; i++) {
        pair<int, int> our = hash.get(0, i - 1);
        
        bool bad = false;
        for(int j = 0; j < n; j += i) {
            int r = j + i - 1;
            if(r >= n) {
                r = n;
                int len = n - j;
                pair<int, int> here = hash.get(j, n - 1);
                pair<int, int> init = hash.get(0, len - 1);
                if(here != init) {
                    bad = true;
                    break;
                }
            } else {
                pair<int, int> here = hash.get(j, r);
                if(here != our) {
                    bad = true;
                    break;
                }
            }
        }
        if(!bad) ans.push_back(i);
    }
    for(int i: ans) cout << i << " ";
    cout << '\n';
}