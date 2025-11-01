//
// d.cpp
// Created by Wasif on 10/28/25 at 19:58:28.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> p = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53};
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        bool odd = false;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            a[i] = x;
            if((a[i] & 1)) {
                odd = true;
            }
        }
        if(odd) {
            cout << 2 << '\n';
            continue;
        }
        int ans = 0;
        for(int i: p) {
            for(int j = 0; j < n; j++) {
                if(__gcd(a[j], i) == 1) {
                    ans = i;
                    break;
                }
            }
            if(ans != 0) break;
        }
        cout << ans << '\n';
    }
}