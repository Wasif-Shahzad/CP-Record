//
// b.cpp
// Created by Wasif on 10/04/25 at 06:27:51.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, a, b;
    cin >> n >> a >> b;
    int ans = 0;
    for(int x = 1; x <= min(a, b); x++) {
        vector<int> here(n + 1, 0);
        here[1] = here[n] = x;
        int ta = a - x, tb = b - x;
        int c = 2;
        while(c < n && ta >= x) {
            here[c++] = ta;
            ta -= x;
        }
        while(c < n && tb >= x) {
            here[c++] = tb;
            tb -= x;
        }
        if(c == n) ans = x;
    }
    cout << ans << '\n';
    
}