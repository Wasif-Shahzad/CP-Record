//
// e.cpp
// Created by Wasif on 12/07/25 at 23:46:38.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int ask(int i, int j) {
    cout << "? " << i << " " << j << endl;
    int x; cin >> x;
    return x;
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> ans(n + 1);
        for(int i = 1; i + 2 <= n; i += 3) {
            int f = ask(i, i + 1);
            int s = ask(i + 1, i + 2);
            int g = __gcd(f, s);
            ans[i + 1] = g;
            ans[i] = f / g;
            ans[i + 2] = s / g;
        }
        if(n % 3) {
            int u = n / 3 * 3;
            for(int j = 1; j <= n % 3; j++) {
                int s = ask(1, u + j);
                ans[u + j] = s / ans[1];
            }
        }
        cout << "! ";
        for(int i = 1; i <= n; i++) cout << ans[i] << " ";
        cout << endl;
    }
}