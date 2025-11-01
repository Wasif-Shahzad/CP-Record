//
// b.cpp
// Created by Wasif on 09/09/25 at 19:32:38.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int concat(int x, int y) {
    string s = to_string(x) + to_string(y);
    return stoll(s);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        int ans = -1;
        if(n % 2 == 0) {
            for(int i = 1; i * i <= n; i++) {
                if(n % i == 0) {
                    int up = concat(n, i);
                    if(up % (n + i) == 0) {
                        ans = i;
                        break;
                    }
                    up = concat(n, n / i);
                    if(up % (n + n / i) == 0) {
                        ans = n / i;
                        break;
                    }
                }
            }
        } else {
            ans = 2 * n;
        }
        cout << ans << '\n';
    }
}