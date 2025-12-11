//
// b.cpp
// Created by Wasif on 12/02/25 at 09:36:07.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int N = 1e5+1;
int home[N], away[N];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> kits(n);
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        home[x]++;
        away[x]++;
        kits[i] = {x, y};
    }

    for(int i = 0; i < n; i++) {
        int x = n - 1, y = n - 1;
        int rem = home[kits[i].second];
        x += rem;
        y -= rem;
        cout << x << " " << y << '\n';
    }
}