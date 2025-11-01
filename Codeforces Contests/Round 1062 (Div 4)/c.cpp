//
// c.cpp
// Created by Wasif on 10/28/25 at 19:44:06.
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
    while(T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        bool even = false, odd = false;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] & 1) odd = true;
            else even = true;
        }
        if(even && odd) {
            sort(a.begin(), a.end());
        }
        for(int i = 0; i < n; i++) cout << a[i] << " ";
        cout << '\n';
    }
}