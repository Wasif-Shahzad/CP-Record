//
// f.cpp
// Created by wasifshahzad on 01/01/26 at 21:06:55.
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
    while(T--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<int> suff(n + 1, 0);
        suff[n] = 1;
        for(int i = 0; i < m; i++) {
            int x; cin >> x;
            suff[x - 1]++;
        }
        vector<int> freq(26, 0);
        int cur = 1;
        for(int i = n - 1; i >= 0; i--) {
            cur += suff[i];
            freq[s[i] - 'a'] += cur;
        }
        for(int i = 0; i < 26; i++) cout << freq[i] << " ";
        cout << '\n';
    }
}