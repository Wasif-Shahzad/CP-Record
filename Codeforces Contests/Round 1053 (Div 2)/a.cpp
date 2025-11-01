//
// a.cpp
// Created by Wasif on 09/24/25 at 16:29:23.
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
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        for(int i = 0; i < m; i++) {
            cin >> a[i];
        }
        bool fl = true;
        for(int i = 1; i < m; i++) {
            if(a[i] != a[i - 1] + 1) {
                fl = false;
                break;
            }
        }
        if(!fl) cout << 1 << '\n';
        else {
            cout << n - a[m - 1] + 1 << '\n';
        }
    }
}