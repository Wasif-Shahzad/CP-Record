//
// a.cpp
// Created by wasifshahzad on 8/27/25 at 08:05:32.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

/*
 *n even
 * even blue  even red
 * n odd
 * odd blue odd red
 */

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n, a, b;
        cin >> n >> a >> b;
        if (n & 1) {
            if (b & 1) {
                if (a <= b) cout << "Yes\n";
                else if (a & 1) cout << "Yes\n";
                else cout << "No\n";
            } else {
                cout << "No\n";
            }
        } else if (b % 2 == 0) {
            if (b >= a) cout << "Yes\n";
            else if (a % 2 == 0) cout << "Yes\n";
            else cout << "No\n";
        } else cout << "No\n";
    }
}