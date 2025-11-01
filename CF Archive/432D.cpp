//
// 432D.cpp
// Created by wasifshahzad on 8/24/25 at 12:49:21.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<int> kmp(string& s) {
    int n = s.size();
    vector<int> pi(n);
    pi[0] = 0;
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
        if (s[j] == s[i]) j++;
        pi[i] = j;
    }
    return pi;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    int n = s.size();
    vector<int> pi = kmp(s);
    vector<int> freq(n + 1, 0);
    for (int i = 0; i < n; i++) {
        freq[pi[i]]++;
    }
    for (int i = n - 1; i > 0; i--) {
        freq[pi[i - 1]] += freq[i];
    }
    for (int i = 0; i <= n; i++) {
        freq[i]++;
    }
    vector<int> valid;
    for (int i = n; i > 0; i = pi[i - 1]) {
        valid.push_back(i);
    }
    sort(valid.begin(), valid.end());
    cout << valid.size() << '\n';
    for (const int l: valid) {
        cout << l << " " << freq[l] << '\n';
    }
}
