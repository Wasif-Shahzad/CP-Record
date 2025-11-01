//
// 2144B.cpp
// Created by Wasif on 09/16/25 at 20:02:40.
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
        int cnt = 0;
        vector<int> a(n), loc(n + 1, -1);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] == 0) cnt++;
            else loc[a[i]] = i;
        } 
        if(cnt <= 1) {
            int mis = 1;
            while(mis <= n && loc[mis] != -1) mis++;
            for(int i = 0; i < n; i++) {
                if(a[i] == 0) a[i] = mis;
            }
            int l = 0, r = n - 1;
            while(l < n && a[l] == l + 1) l++;
            while(r > l && a[r] == r + 1) r--;
            if(l == r) cout << 0 << '\n';
            else cout << r - l + 1 << '\n';
        } else {
            int l = 0, r = n - 1;
            while(l < n && a[l] == l + 1) l++;
            while(r > l && a[r] == r + 1) r--;
            if(l == r) cout << 0 << '\n';
            else cout << r - l + 1 << '\n';
        }
    }
}