//
// 1845D.cpp
// Created by wasifshahzad on 12/31/25 at 12:46:02.
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
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        if(*min_element(a.begin(), a.end()) > 0) {
            cout << (int)1e18 << '\n';
            continue;
        }
        if(*max_element(a.begin(), a.end()) < 0) {
            cout << 0 << '\n';
            continue;
        }
        int mn = a[0], k = 0, sm = a[0], l = 0, r = 0, ll = 0;
        for(int i = 1; i < n; i++) {
            if(sm > 0) {
                sm = a[i];
                ll = i;
            } else {
                sm += a[i];
            }
            if(sm < mn) {
                mn = sm;
                l = ll, r = i;
            }
        } 
        for(int i = 0; i < l; i++) k += a[i];
        cout << k << '\n';
    }
}