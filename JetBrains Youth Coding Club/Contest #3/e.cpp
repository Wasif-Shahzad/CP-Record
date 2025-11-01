//
// e.cpp
// Created by Wasif on 10/19/25 at 10:02:45.
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
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if(a[n - 1] == 15) cout << "DOWN\n";
    else if(a[n - 1] == 0) cout << "UP\n";
    else if(n == 1) cout << -1 << '\n';
    else if(a[n - 1] > a[n - 2]) cout << "UP\n";
    else cout << "DOWN\n";
}