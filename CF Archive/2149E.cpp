//
// 2149E.cpp
// Created by Wasif on 09/27/25 at 12:31:59.
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
        int n, k, l, r;
        cin >> n >> k >> l >> r;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int p1 = 0, p2 = -1;
        map<int, int> freq;
        int ans = 0;
        while(p1 < n) {
            while(p2 + 1 < n && freq.size() < k) {
                freq[a[++p2]]++;
            }
            int up = p1 + r - 1, lo = p1 + l - 1;
            if(lo >= p2) ans += up - lo + 1;
            else ans += max(0ll, up - p2 + 1);
            if(freq[a[p1]] == 1) {
                freq.erase(a[p1]);
            } else {
                freq[a[p1]]--;
            }
            p1++;
        }
        cout << ans << '\n';
    }
}