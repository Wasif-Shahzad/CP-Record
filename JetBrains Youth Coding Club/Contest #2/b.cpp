//
// b.cpp
// Created by Wasif on 10/11/25 at 09:53:49.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int mn = 1e9 + 10;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        mn = min(mn, a[i]);
    }
    int j = -1, ans = 1e9;
    for(int i = 0; i < n; i++) {
        if(a[i] == mn && j == -1) j = i;
        else if(a[i] == mn) {
            ans = min(ans, i - j);
            j = i;
        }
    }
    cout << ans << '\n';
}