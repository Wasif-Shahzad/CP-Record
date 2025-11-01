//
// c.cpp
// Created by Wasif on 09/09/25 at 19:32:40.
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
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        int ans = 0, cost = 0;
        for(int i = 0; i + 1 < n; i += 2) {
            ans += a[i] - a[i + 1];
        }
        if(n & 1) ans += a[n - 1];
        cost = (n & 1 ? n - 1 : n - 2);
        int orig = ans;
        ans += cost;
        set<int> x, y;
        if(n % 2 == 0) x.insert(n - 1 + 2 * a[n - 1]);
        else y.insert(n - 1 - 2 * a[n - 1]);
        for(int i = n - 2; i >= 0; i--) {
            if((i + 1) & 1) {
                if(x.size()) {
                    int bst = *x.rbegin();
                    ans = max(ans, orig + bst - i - 2 * a[i]);
                } 
                y.insert(i - 2 * a[i]);
            } else {
                if(y.size()) {
                    int bst = *y.rbegin();
                    ans = max(ans, orig + bst - i + 2 * a[i]);
                }
                x.insert(i + 2 * a[i]);
            }
        }
        cout << ans << '\n';
    }
}