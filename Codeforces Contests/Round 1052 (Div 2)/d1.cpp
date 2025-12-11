//
// d1.cpp
// Created by Wasif on 12/08/25 at 21:41:15.
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
        int l, r;
        cin >> l >> r;
        int n = r - l + 1;
        vector<int> ans(n, -1);
        vector<int> vac(n, 1);
        for(int i = r; i >= l; i--) {
            for(int j = 31; j >= 0; j--) {
                int need = ((1ll << j) - 1) ^ i;
                if(need > r || need < l) continue;
                if(!vac[need - l]) continue;
                vac[need - l] = 0;
                ans[i - l] = need;
                break;
            }
        }
        int j = -1;
        for(int i = 0; i < n; i++) {
            if(ans[i] == -1) {
                j = i;
                break;
            }
        }
        if(j != -1) {
            for(int i = 0; i < n; i++) {
                if(vac[i]) {
                    ans[j] = i + l;
                    break;
                }
            }
        }
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += (l + i) | ans[i];
        }
        cout << sum << '\n';
        for(int i = 0; i < n; i++) cout << ans[i] << " ";
        cout << '\n';
    }
}