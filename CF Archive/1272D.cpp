//
// 1272D.cpp
// Created by wasifshahzad on 01/11/26 at 21:27:46.
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
    for(int &i: a) cin >> i;
    vector<int> pref(n), suff(n);
    pref[0] = 1;
    int cur = 1;
    for(int i = 1; i < n; i++) {
        if(a[i] > a[i - 1]) {
            cur++;
        } else {
            cur = 1;
        }
        pref[i] = cur;
    }
    suff[n - 1] = 1;
    int ans = 0;
    cur = 1;
    for(int i = n - 2; i>= 0; i--) {
        if(a[i] < a[i + 1]) {
            cur++;
        } else {
            cur = 1;
        }
        suff[i] = cur;
        ans = max(ans, cur);
    }
    ans = max({ans, suff[1], pref[n - 2]});
    for(int i = 1; i + 1 < n; i++) {
        if(a[i + 1] > a[i - 1]) {
            ans = max(ans, pref[i - 1] + suff[i + 1]);
        }
    }
    cout << ans << '\n';
}