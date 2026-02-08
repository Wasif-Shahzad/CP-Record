//
// b.cpp
// Created by wasifshahzad on 12/27/25 at 19:28:51.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        string s;
        cin >> s;
        int n = s.size();
        if(count(s.begin(), s.end(), 'u') == 0) {
            cout << 0 << '\n';
            continue;
        }
        int ans = 0;
        if(s[0] == 'u') {
            s[0] = 's';
            ans++;
        }
        if(s[n - 1] == 'u') {
            s[n - 1] = 's';
            ans++;
        }
        for(int i = 1; i < n; i++) {
            if(s[i] == 'u' && s[i - 1] == 'u') {
                s[i] = 's';
                ans++;
            }
        }
        cout << ans << '\n';
    }
}