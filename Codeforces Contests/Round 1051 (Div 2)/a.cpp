//
// a.cpp
// Created by Wasif on 09/17/25 at 19:29:22.
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
        int l, r;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] == n) {
                l = r = i;
            }
        }
        int cur = n;
        bool bad = false;
        while(true) {
            if(l == 0 && r == n - 1) break;
            if(l > 0 && a[l - 1] == cur - 1) {
                cur--;
                l--;
                continue;
            }
            if(r + 1 < n && a[r + 1] == cur - 1) {
                cur--;
                r++;
                continue;
            }
            bad = true;
            break;
        }
        cout << (!bad ? "YES" : "NO") << '\n';
    }
}