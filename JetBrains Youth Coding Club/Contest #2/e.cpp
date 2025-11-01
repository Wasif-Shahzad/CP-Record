//
// e.cpp
// Created by Wasif on 10/11/25 at 12:21:40.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int n = s.size();
    vector<vector<vector<int>>> f(26, vector<vector<int>>(26, vector<int>(n + 1, 0)));
    vector<int> cnt(26, 0);
    for(int i = 0; i < n; i++) {
        cnt[s[i] - 'a']++;
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            int dist = (i > j ? n - i + j : j - i);
            f[s[i] - 'a'][s[j] - 'a'][dist]++;
        }
    }
    vector<vector<vector<int>>> has(26, vector<vector<int>>(n + 1));
    for(int ch1 = 0; ch1 < 26; ch1++) {
        for(int ch2 = 0; ch2 < 26; ch2++) {
            for(int d = 1; d <= n; d++) {
                if(f[ch1][ch2][d] == 1) has[ch1][d].push_back(ch2);
            }
        }
    }
    // has[ch1][d].size() == cnt[ch1] means the probability is 1
    // otherwise, we sum
    long double num = 0;
    for(int i = 0; i < 26; i++) {
        int mx = 0;
        for(int d = 1; d <= n; d++) {
            mx = max(mx, (int)has[i][d].size());
        }
        num += mx;
    }
    long double prob = num / (1.0L * n);
    cout << setprecision(6) << fixed << prob << '\n';
}