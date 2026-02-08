//
// d.cpp
// Created by wasifshahzad on 01/10/26 at 16:57:23.
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
    #define all(x) x.begin(), x.end()
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int &i: a) cin >> i;
    sort(a.begin(), a.end());
    vector<int> pref(n, 0);
    pref[0] = a[0] - 1;
    for(int i = 1; i < n ;i++) {
        pref[i] = pref[i - 1] + a[i] - a[i - 1] - 1;
    }
    while(q--) {
        int x, y;
        cin >> x >> y;
        int j = upper_bound(all(a), x) - a.begin();
        if(j == n) {
            cout << x + y - (x != a[n - 1]) << '\n';
            continue;
        }
        if(j > 0 && a[j - 1] == x) x++;
        int here = a[j] - x;
        if(y <= here) {
            cout << x + y - 1 << '\n';
            continue;
        }
        int rem = y - (a[j] - x);
        int k = lower_bound(all(pref), pref[j] + rem) - pref.begin();
        if(k == n) {
            rem -= pref[n - 1] - pref[j];
            cout << a[n - 1] + rem << '\n';
            continue;
        }
        if(pref[k] == pref[j] + rem) {
            cout << a[k] - 1 << '\n';
        } else {
            rem -= pref[k - 1] - pref[j];
            cout << a[k - 1] + rem << '\n';
        }
    }
}