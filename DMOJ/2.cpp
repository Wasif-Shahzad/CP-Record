//
// 2.cpp
// Created by wasifshahzad on 12/24/25 at 18:56:54.
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
    int n, m;
    cin >> n >> m;
    vector<int> l(n), f(m);
    for(int i = 0; i < n; i++) cin >> l[i];
    for(int i = 0; i < m; i++) cin >> f[i];
    l.push_back(-100000000000000);
    l.push_back(100000000000000);
    sort(l.begin(), l.end());
    sort(f.begin(), f.end());
    n += 2;
    if(n == 3) {
        cout << f[m - 1] - f[0] << '\n';
        return 0;
    }
    int ans = 0, j = 0;
    for(int i = 1; i < n; i++) {
        if(j == m) break;
        if(f[j] > l[i]) continue;
        int bst = l[i] - l[i - 1];
        int gap = f[j] - l[i - 1];
        int k;
        for(k = j + 1; k < m; k++) {
            if(f[k] > l[i]) {
                break;
            } else {
                gap = max(gap, f[k] - f[k - 1]);
            }
        }
        gap = max(gap, l[i] - f[k - 1]);
        bst -= gap;
        ans += bst;
        j = k;
    }
    cout << ans << '\n';
}