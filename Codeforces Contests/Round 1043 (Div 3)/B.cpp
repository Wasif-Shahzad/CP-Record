//
// B.cpp
// Created by wasifshahzad on 8/21/25 at 21:11:55.
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
        vector<int> seq;
        for (int i = 10; i < 1e18; i *= 10) {
            if (n % (i + 1) == 0) {
                seq.push_back(n / (i + 1));
            }
        }
        sort(seq.begin(), seq.end());
        cout << seq.size() << '\n';
        for (int i: seq) cout << i << " ";
        if (seq.size()) cout << '\n';
    }
}