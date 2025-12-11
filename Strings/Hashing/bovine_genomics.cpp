//
// bovine_genomics.cpp
// Created by Wasif on 11/16/25 at 12:46:17.
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
vector<int> p1, p2;
int mod1 = 1e9+7, mod2 = 1e9+9;

struct Hash{
    vector<int> pref1, pref2;

    void build(string& s) {
        int n = s.size();

        pref1.assign(n + 1, 0);
        pref2.assign(n + 1, 0);

        for(int i = 0; i < n; i++) {
            pref1[i + 1] = ((pref1[i] * base) % mod1 + (s[i] - 'A' + 1)) % mod1;
            pref2[i + 1] = ((pref2[i] * base) % mod2 + (s[i] - 'A' + 1)) % mod2;
        }
    }

    inline pair<int, int> get(int l, int r) {
        int len = r - l + 1;
        int h1 = ((pref1[r + 1] - (pref1[l] * p1[len]) % mod1) + mod1) % mod1;
        int h2 = ((pref2[r + 1] - (pref2[l] * p2[len]) % mod2) + mod2) % mod2;
        return {h1 % mod1, h2 % mod2};
    }
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);

    int n, m;
    cin >> n >> m;
    p1.push_back(1); p2.push_back(1);
    while(p1.size() <= m) {
        p1.push_back((p1.back() * base) % mod1);
        p2.push_back((p2.back() * base) % mod2);
    }
    vector<Hash> a(n), b(n);
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        a[i].build(s);
    }    
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        b[i].build(s);
    }
    auto f = [&] (int k) -> bool {
        for(int l = 0; l + k <= m; l++) {
            int r = l + k - 1;
            vector<pair<int, int>> good, bad;
            for(int i = 0; i < n; i++) {
                auto h = a[i].get(l, r);
                good.push_back(h);
            }
            bool can = true;
            for(int i = 0; i < n; i++) {
                auto h = b[i].get(l, r);
                bad.push_back(h);
            }
            sort(good.begin(), good.end());
            good.erase(unique(good.begin(), good.end()), good.end());
            sort(bad.begin(), bad.end());
            bad.erase(unique(bad.begin(), bad.end()), bad.end());
            int x = 0, y = 0;
            while(x < good.size() && y < bad.size()) {
                while(x < good.size() && good[x] < bad[y]) x++;
                if(good[x] == bad[y]) {
                    can = false;
                    break;
                }
                y++;
            }
            if(can) {
                return true;
            }
        }
        return false;
    };
    int lo = 1, hi = m + 1;
    while(hi > lo + 1) {
        int mid = (hi + lo) / 2;
        if(f(mid)) hi = mid;
        else lo = mid;
    }
    cout << hi << '\n';
}