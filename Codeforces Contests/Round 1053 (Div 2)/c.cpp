//
// c.cpp
// Created by Wasif on 09/24/25 at 16:29:35.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> a(2 * n);
        for(int i = 0; i < 2 * n; i++) {
            cin >> a[i];
        }
        vector<int> p1(2 * n, 0), p2(2 * n, 0);
        for(int i = 1; i < 2 * n; i += 2) {
            p1[i] = a[i] - a[i - 1];
        }
        for(int i = 2; i < 2 * n; i += 2) {
            p2[i] = a[i] - a[i - 1];
        }
        for(int i = 2; i < 2 * n; i++) {
            p1[i] += p1[i - 1];
            p2[i] += p2[i - 1];
        }
        cout << p1[2 * n - 1] << ' ';
        int prev = 0;
        for(int i = 0, j = 2 * n - 1; i + 1 < n; i++, j--) {
            prev += a[j] - a[i];
            int ans = prev;
            if(i & 1) {
                ans += p1[j - 1] - p1[i];
            } else {
                ans += p2[j - 1] - p2[i];
            }
            cout << ans << " ";
        }
        cout << '\n';
    }
}