//
// extra.cpp
// Created by Wasif on 09/10/25 at 18:15:46.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, x;
    cin >> n >> k >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = 1;
    vector<int> gaps;
    for(int i = 1; i < n; i++) {
        if(a[i] - a[i - 1] > x) {
            int need = (a[i] - a[i - 1] - 1) / x;
            ans++;
            gaps.push_back(need);
        }
    }
    sort(gaps.begin(), gaps.end());
    for(int i: gaps) {
        if(i <= k) {
            k -= i;
            ans--;
        } else {
            break;
        }
    }
    cout << ans << '\n';
}   