//
// f.cpp
// Created by Wasif on 10/11/25 at 17:48:16.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

bool check(int mask) {
    for(int i = 0; i < 30; i++) {
        if(((1 << i) & mask) && ((1 << (i + 1)) & mask)) return false;
    }
    return true;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> left, ld, right, rd;
    int l = n / 2, r = n - l;
    auto rec1 = [&] (int i, int sum, auto&& self) -> void{
        if(i == l - 1) {
            ld.push_back((sum + a[l - 1]) % m);
            left.push_back(sum % m);
            return;
        }
        if(i >= l) {
            left.push_back(sum % m);
            return;
        }
        self(i + 2, sum + a[i], self);
        self(i + 1, sum, self);
    };
    rec1(0, 0, rec1);
    auto rec2 = [&] (int i, int sum, bool bad, auto&& self) -> void{
        if(i >= n) {
            if(bad) right.push_back(sum % m);
            else rd.push_back(sum % m);
            return;
        }
        if(i == l) {
            self(i + 2, sum + a[i], true, self);
            self(i + 1, sum, false, self);
            return;
        }
        self(i + 2, sum + a[i], bad, self);
        self(i + 1, sum, bad, self);
    };
    rec2(l, 0, 0, rec2);
    // left combines with both right and rd
    // ld only combineds with rd
    unordered_map<int, int, custom_hash> f1, f2;
    for(int s: left) f1[s]++;
    for(int s: right) f2[s]++;
    for(int s: rd) f2[s]++;
    int ans = 0;
    for(auto [v, c]: f1) {
        int rem = (m - v) % m;
        ans += c * f2[rem];
    }
    f1.clear();
    f2.clear();
    for(int s: ld) f1[s]++;
    for(int s: rd) f2[s]++;
    for(auto [v, c]: f1) {
        int rem = (m - v) % m;
        ans += c * f2[rem];
    }
    cout << ans << '\n';
}