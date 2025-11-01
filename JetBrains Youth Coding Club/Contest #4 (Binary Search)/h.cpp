//
// h.cpp
// Created by Wasif on 10/30/25 at 12:19:42.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int n;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    // find min(w) such that height = 1
    // we get max(w') such that height = curheight + 1
    // find min(w'') such that height = curheight + 1
    // repeat this recursively
    
}