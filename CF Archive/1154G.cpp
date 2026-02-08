//
// 1154G.cpp
// Created by wasifshahzad on 12/21/25 at 12:56:34.
//

#include <bits/stdc++.h>
using namespace std;
// #define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;
const int M = 1e7+1;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> ind(M, -1), f(M, 0), sind(M, -1);
    for(int i = 1; i <= n; i++) {
        int x; cin >> x;
        if(f[x] == 0) sind[x] = i;
        ind[x] = i;
        f[x]++;
    }
    long long bst = (long long)1e15, x = -1, y = -1;
    for(int g = 1; g < M; g++) {
        int a = -1, b = -1;
        for(int j = g; j < M; j += g) {
            if(f[j]) {
                if(a == -1) {
                    if(f[j] > 1) {
                        a = b = j;
                        break;
                    }
                    a = j;
                } else if(b == -1) {
                    b = j;
                    break;
                }
            }
        }
        if(a == -1 || b == -1) continue;
        long long here = 1ll * a / g * b;
        if(here < bst) {
            bst = here;
            x = a, y = b;
        }
    }
    int i, j;
    if(x == y) i = sind[x], j = ind[x];
    else i = ind[x], j = ind[y];
    if(i > j) swap(i, j);
    cout << i << " " << j << '\n';
}