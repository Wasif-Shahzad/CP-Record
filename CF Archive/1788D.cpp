//
// 1788D.cpp
// Created by Wasif on 11/26/25 at 21:12:53.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int mod = 1e9+7;

int power(int a, int b) {
    int ans = 1;
    while(b > 0) {
        if(b & 1) ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> x(n + 1);
    for(int i = 0; i < n; i++) {
        cin >> x[i];
    }

    int ans = 0;

    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            // i moves right, j moves left
            int lo = j, hi = n;
            while(hi > lo + 1) {
                int mid = (hi + lo) / 2;
                if(x[mid] - x[j] >= x[j] - x[i]) hi = mid;
                else lo = mid;
            }
            int k = hi;
            lo = -1, hi = i;
            while(hi > lo + 1) {
                int mid = (hi + lo) / 2;
                if(x[i] - x[mid] > x[j] - x[i]) lo = mid;
                else hi = mid;
            }
            int K = lo;
            int here = power(2, K + 1) * power(2, n - k) % mod;
            ans = (ans + here) % mod;
        }
    }    

    cout << ans << '\n';
}