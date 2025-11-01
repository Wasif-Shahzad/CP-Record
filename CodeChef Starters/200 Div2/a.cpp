//
// a.cpp
// Created by wasifshahzad on 8/20/25 at 19:28:46.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            a[i] %= 2;
        }
        vector<int> seq1, seq2;
        for (int i = 0; i < n; i++) {
            if ((a[i] == 0 && seq1.empty()) || (seq1.size() && a[i] != seq1.back())) {
                seq1.push_back(a[i]);
            }
            if ((a[i] == 1 && seq2.empty()) || (seq2.size() && a[i] != seq2.back())) {
                seq2.push_back(a[i]);
            }
        }
        cout << max(seq1.size(), seq2.size()) << endl;
    }
}