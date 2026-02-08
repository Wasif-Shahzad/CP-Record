//
// a.cpp
// Created by wasifshahzad on 12/17/25 at 13:15:00.
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
    int n, m;
    cin >> n >> m;
    vector<int> freq(26, 0), ofreq(26, 0);
    vector<string> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        for(auto j: a[i]) {
            freq[j - 'A']++;
            ofreq[j - 'A']++;
        }
    }
    for(int i = 0; i < 26; i++) freq[i] *= m;
    auto f = [&] (int i, int x) -> bool {
        // we only use x of our copies
        vector<int> rem(26, 0);
        for(int j = 0; j < 26; j++) {
            rem[j] = freq[j] - ofreq[j] * x;
        }
        vector<int> need(26, 0);
        for(auto j: a[i]) {
            need[j - 'A']++;
        }
        for(int j = 0; j < 26; j++) {
            if(need[j] > rem[j]) return false;
        }
        return true;
    };
    for(int l = 0; l < n; l++) {
        for(auto j: a[l]) {
            freq[j - 'A'] -= m;
            ofreq[j - 'A']--;
        }
        int lo = -1, hi = m;
        if(!f(l, 0)) {
            cout << -1 << " ";
        } else {
            while(hi > lo + 1) {
                int mid = (hi + lo) / 2;
                if(f(l, mid)) lo = mid;
                else hi = mid;
            }
            cout << lo << " ";
        }
        for(auto j: a[l]) {
            freq[j - 'A'] += m;
            ofreq[j - 'A']++;
        }
    }
    cout << '\n';
}