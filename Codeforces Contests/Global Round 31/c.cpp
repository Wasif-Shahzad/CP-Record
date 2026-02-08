//
// c.cpp
// Created by wasifshahzad on 12/19/25 at 19:53:05.
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
        int n, k;
        cin >> n >> k;
        if(k & 1) {
            for(int i = 0; i < k; i++) cout << n << " ";
            cout << '\n';
            continue;
        }
        vector<int> ans(k, n);
        int msb = 0;
        for(int i = 0; i <= 30; i++) {
            if((1 << i) & n) msb = i;
        }
        ans[k - 2] = (1 << msb);
        ans[k - 1] = n ^ ans[k - 2];
        for(int i = 30; i >= 0; i--) {
            if((1 << i) & n) continue;
            // set in last and second last
            if((ans[k - 2] | (1 << i)) > n) continue;
            if((ans[k - 1] | (1 << i)) > n) continue;
            ans[k - 1] |= (1 << i);
            ans[k - 2] |= (1 << i);
        }
        for(int i = 0; i < k; i++) cout << ans[i] << " ";
        cout << '\n';
    }
}