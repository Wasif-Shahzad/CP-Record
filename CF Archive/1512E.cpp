//
// 1512E.cpp
// Created by wasifshahzad on 01/11/26 at 21:49:31.
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
        int n, l, r, s;
        cin >> n >> l >> r >> s;
        int m = r - l + 1;
        if(m * (m + 1) / 2 > s) {
            cout << -1 << '\n';
            continue;
        }        
        vector<int> our(m);
        iota(our.begin(), our.end(), 1);
        int sum = m * (m + 1) / 2;
        int j = m - 1;
        while(sum < s && j >= 0) {
            if(j == m - 1) {
                if(our[j] < n) {
                    our[j]++;
                    sum++;
                } else {
                    j--;
                }
            } else {
                if(our[j] + 1 < our[j + 1]) {
                    our[j]++;
                    sum++;
                } else {
                    j--;
                }
            }
        }
        if(sum < s) {
            cout << -1 << '\n';
            continue;
        }
        set<int> st;
        for(int i = 1; i <= n; i++) st.insert(i);
        for(int i: our) st.erase(i);
        for(int i = 1; i < l; i++) {
            cout << *st.begin() << " ";
            st.erase(*st.begin());
        }
        for(int i = l; i <= r; i++) {
            cout << our.back() << " ";
            our.pop_back();
        }
        for(int i = r + 1; i <= n; i++) {
            cout << *st.begin() << " ";
            st.erase(*st.begin());
        }
        cout << '\n';
    }
}