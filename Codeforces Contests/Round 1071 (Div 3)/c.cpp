//
// c.cpp
// Created by wasifshahzad on 12/23/25 at 19:33:24.
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
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }   
        sort(a.begin(), a.end());
        auto f = [&] (int x) -> bool {
            for(int i = 1; i < n; i++) {
                int c = a[i] - a[0];
                if(a[i] % c != a[0]) return false;
                if(c < x) return false;
            }
            return true;
        };
        if(!f(a[0] + 1)) {
            cout << a[0] << '\n';
            continue;
        }
        int lo = a[0], hi = a[1];
        while(hi > lo + 1) {
            int mid = (hi + lo) / 2;
            if(f(mid)) lo = mid;
            else hi = mid;
        }
        cout << lo << '\n';
    }
}