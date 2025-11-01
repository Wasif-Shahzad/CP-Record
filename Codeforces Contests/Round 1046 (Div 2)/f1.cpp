//
// f1.cpp
// Created by wasifshahzad on 8/29/25 at 11:09:38.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int ask(vector<int>& a) {
    cout << "? " << a.size() << " ";
    for (int i: a) cout << i << " ";
    cout << endl;
    int r;
    cin >> r;
    return r;
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    vector<int> init(1e5, 1);
    const int MAX = 1e5;
    int T;
    cin >> T;
    while (T--) {
        int k = ask(init);
        vector<int> cands;
        for (int i = 1; i <= MAX; i++) {
            if ((MAX + i - 1) / i == k) {
                cands.push_back(i);
            }
        }
        int l = cands[0], r = cands.back();
        if (l == r) {
            cout << "! " << l << endl;
            continue;
        }
        vector<int> now;
        for (int i = 1; i <= r - l; i++) {
            now.push_back(l);
            now.push_back(i);
        }
        int r2 = ask(now);
        int w = 2 * r - l - r2;
        cout << "! " << w << endl;
    }
}