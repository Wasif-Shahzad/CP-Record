//
// b.cpp
// Created by wasifshahzad on 8/28/25 at 19:32:41.
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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int cur = 1;
        vector<int> a(n, -1);
        set<int> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '1') {
                a[i] = cur++;
            } else {
                st.insert(i);
            }
        }
        int i = -1;
        bool good = true;
        while (i < n) {
            if (i + k >= n) {
                break;
            }
            auto it = st.upper_bound(i + k);
            if (it == st.begin()) {
                good = false;
                break;
            }
            it--;
            int j = *it;
            st.erase(j);
            a[j] = cur++;
            i = j;
        }
        for (int i = 0; i < n; i++) {
            if (a[i] == -1) {
                a[i] = cur++;
            }
        }
        cout << (good ? "YES" : "NO") << '\n';
        if (good) {
            for (int i = 0; i < n; i++) cout << a[i] << " ";
            cout << '\n';
        }
    }
}