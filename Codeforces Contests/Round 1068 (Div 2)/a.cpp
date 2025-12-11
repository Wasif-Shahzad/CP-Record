//
// a.cpp
// Created by Wasif on 12/05/25 at 19:35:35.
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
        string s;
        cin >> s;
        int ans = 0, j = -1;
        for(int i = 0; i < n; i++) {
            if(s[i] == '0' && i > j) ans++;
            else if(s[i] == '1') {
                j = max(j, i + k);
            }
        }
        cout << ans << '\n';
    }
}