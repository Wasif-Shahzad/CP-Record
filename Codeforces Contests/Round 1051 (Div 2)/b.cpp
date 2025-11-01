//
// b.cpp
// Created by Wasif on 09/17/25 at 19:29:29.
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
        int n, k;
        cin >> n >> k;
        vector<int> a(n), b(k);
        int tot = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            tot += a[i];
        }
        for(int i = 0; i < k; i++) {
            cin >> b[i];
        }
        sort(a.rbegin(), a.rend());
        sort(b.begin(), b.end());
        int rm = 0, j = 0;
        for(int i = 0; i < n && j < k; i++) {
            if(i + b[j] - 1 < n) {
                rm += a[i + b[j] - 1];
                i += b[j] - 1;
            }
            j++;
        }
        cout << tot - rm << '\n';
    }
}