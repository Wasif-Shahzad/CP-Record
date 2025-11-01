//
// b.cpp
// Created by Wasif on 10/25/25 at 17:07:11.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    int sm = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        sm += a[i];
    }
    for(int i = 0; i < n; i++) {
        if(sm - a[i] == m) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";
}