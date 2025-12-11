//
// e.cpp
// Created by Wasif on 11/24/25 at 08:57:30.
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

    if(n % 4 == 0 || n % 4 == 1) {
        vector<int> ans(n);
        iota(ans.begin(), ans.end(), 1);
        int i = 1, j = n - 2;
        int x = 1, y = 2, z = n - 1, Z = n;
        while(j > i) {
            ans[i - 1] = y;
            ans[i] = Z;
            ans[j] = x;
            ans[j + 1] = z;
            i += 2;
            j -= 2;
            x += 2, y += 2;
            z -= 2, Z -= 2;
        }
        for(int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << '\n';
    } else {
        cout << -1 << '\n';
    }
}