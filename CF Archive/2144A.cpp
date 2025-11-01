//
// 2144A.cpp
// Created by Wasif on 09/16/25 at 19:35:34.
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
        int total = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            total += a[i];
        }
        int l = -1, r = -1;
        int pref = 0;
        for(int i = 0; i < n; i++) {
            pref += a[i];
            int suff = a[n - 1];
            for(int j = n - 2; j > i; j--) {
                if(pref % 3 == suff % 3) {
                    int rem = total - pref - suff;
                    if(rem % 3 == pref % 3) {
                        l = i, r = j;
                        break;
                    }
                } else {
                    int rem = (total - pref - suff) % 3;
                    int need = 3 - (pref % 3) - (suff % 3);
                    if(rem == need) {
                        l = i, r = j;
                        break;
                    }
                }
            }
            if(l != -1) break;
        }
        if(l == -1) cout << "0 0\n";
        else cout << l + 1 << " " << r + 1 << '\n';
    }
}