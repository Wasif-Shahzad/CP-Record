//
// e.cpp
// Created by Wasif on 10/04/25 at 07:12:42.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<array<int, 2>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
    }
    int l = -1e9, r = 1e9;
    if(a[0][1] == 2) r = 1899;
    else l = 1900;
    int cur = a[0][0];
    bool flag = false;
    for(int i = 1; i < n; i++) {
        if(a[i][1] != a[i - 1][1]) {
            if(a[i][1] == 2) {
                r = min(r, 1899 - cur);
            } else {
                l = max(l, 1900 - cur);
            }
            if(l > r) {
                flag = true;
                break;
            }
        }
        cur += a[i][0];
    }
    if(l > r) {
        cout << "Impossible\n";
        return 0;
    }
    if(r == 1e9) {
        cout << "Infinity\n";
        return 0;
    }
    r++;
    auto f = [&] (int x) -> bool{
        int cur = x;
        for(int i = 0; i < n; i++){
            int curDiv = (cur < 1900 ? 2 : 1);
            if(curDiv != a[i][1]) return false;
            cur += a[i][0];
        }
        return true;
    };
    if(f(l + 1)) {
        while(r > l + 1) {
            int mid = (l + r) / 2;
            if(f(mid)) l = mid;
            else r = mid;
        }
    }
    int ans = l;
    for(int i = 0; i < n; i++) {
        ans += a[i][0];
    }
    cout << ans << '\n';
}