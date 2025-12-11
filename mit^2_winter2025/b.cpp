//
// b.cpp
// Created by Wasif on 12/07/25 at 23:26:25.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        string a, b;
        cin >> a >> b;
        int n = a.size(), m = b.size();
        int i = 0, j = 0;
        while(i < n && j < m) {
            if(a[i] == b[j]) {
                i++, j++;
                continue;
            }
            if(b[j] == 'N') {
                j++;
                continue;
            }
            // b[j] = p, a[i] = n
            while(i < n && a[i] == 'N') i++;
            if(i < n) {
                j++;
                i++;
            } else {
                break;
            }
        }
        cout << (j == m && i == n ? "Yes" : "No") << '\n';
    }
}