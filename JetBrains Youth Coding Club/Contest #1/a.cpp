//
// a.cpp
// Created by Wasif on 10/04/25 at 06:27:47.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m;
    cin >> m;
    vector<int> a(m);
    int tot = 0;
    for(int i = 0; i < m; i++) {
        cin >> a[i];
        tot += a[i];
    }
    int x, y;
    cin >> x >> y;
    int ans = 0, sum = 0;
    for(int i = 0; i < m; i++) {
        sum += a[i];
        if(sum >= x && sum <= y && tot - sum >= x && tot - sum <= y) {
            ans = i + 2;
            break;
        }
    }
    cout << ans << '\n';
}