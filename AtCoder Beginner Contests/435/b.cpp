//
// b.cpp
// Created by Wasif on 12/06/25 at 17:17:16.
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
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = i; j < n; j++) {
            sum += a[j];    
            bool good = true;
            for(int k = i; k <= j; k++) {
                if(sum % a[k] == 0) {
                    good = false;
                    break;
                }
            }
            if(good) ans++;
        }
    }
    cout << ans << '\n';
}