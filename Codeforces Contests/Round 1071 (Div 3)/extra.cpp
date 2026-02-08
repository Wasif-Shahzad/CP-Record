//
// extra.cpp
// Created by wasifshahzad on 12/23/25 at 20:00:31.
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
    vector<int> a = {0, 1, 2, 3, 4, 5, 6, 7};
    int bst = 0;
    do { 
        int cur = a[0];
        int v = __builtin_popcount(cur);
        for(int i = 1; i < 8; i++) {
            cur &= a[i];
            v += __builtin_popcount(cur);
        }
        if(v == 7) {
            for(int i = 0; i < 8; i++) cout << a[i] << " ";
            cout << '\n';
        }
        bst = max(bst, v);
    } while(next_permutation(a.begin(), a.end()));
}