//
// 1.cpp
// Created by wasifshahzad on 12/24/25 at 18:34:43.
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
    int n;
    cin >> n;
    vector<int> a(n);
    int cnt = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] % 2 == 0) cnt++;
    }
    if(n & 1) cout << "Steven\n";
    else {
        // if we get last even sum with even remaining, we win
        cout << (cnt > (n - 1) / 2 ? "Steven" : "Todd") << '\n';
    }
}