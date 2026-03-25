//
// c.cpp
// Created by wasifshahzad on 03/16/26 at 19:42:44.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

void solve() {
    int a, b, c, m;
    cin >> a >> b >> c >> m;
    int x = 0, y = 0, z = 0;
    int l1 = lcm(a, b), l2 = lcm(a, c), l3 = lcm(b, c), L = lcm(l1, c);
    x += m / a * 6;
    x -= m / l1 * 6;
    x -= m / l2 * 6;
    x += m / L * 6;

    y += m / b * 6;
    y -= m / l1 * 6;
    y -= m / l3 * 6;
    y += m / L * 6;

    z += m / c * 6;
    z -= m / l2 * 6;
    z -= m / l3 * 6;
    z += m / L * 6;

    // div by l1 and not c
    x += m / l1 * 3, y += m / l1 * 3;
    x -= m / L * 3, y -= m / L * 3;

    // div by l2 and not b
    x += m / l2 * 3, z += m / l2 * 3;
    x -= m / L * 3, z -= m / L * 3;

    // div by l3 and not a
    y += m / l3 * 3, z += m / l3 * 3;
    y -= m / L * 3, z -= m / L * 3;

    x += m / L * 2, y += m / L * 2, z += m / L * 2;
    cout << x << " " << y << " " << z << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}