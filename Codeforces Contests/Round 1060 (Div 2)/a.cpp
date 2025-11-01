//
// a.cpp
// Created by Wasif on 10/19/25 at 20:00:43.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int ans = 0;
        int j = -1;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') {
                j = i;
                break;
            }
        }
        if(j == -1) {
            cout << 0 << '\n';
            continue;
        }
        ans = 1;
        for(int i = j + 1; i < n; i++) {
            if(s[i] == '0') continue;
            bool good = false;
            for(j = i - 1; j >= i - k + 1; j--) {
                if(s[j] == '1') {
                    good = true;
                    break;
                }
            }
            if(!good) ans++;
        }
        cout << ans << '\n';
    }
}