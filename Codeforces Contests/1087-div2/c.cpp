//
// c.cpp
// Created by wasifshahzad on 03/22/26 at 13:06:27.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

int ask(int i, int j) {
    assert(i != j);
    cout << "? " << i << " " << j << endl;
    int k;
    cin >> k;
    return k;
}

void solve() {
    int n;
    cin >> n;
    // check the existence of adj zeroes. 1 and 2n are adjacent
    // there can be 2 types of these
    // 2*i = 2*i - 1
    // 2*i = 2*i + 1
    // HAVE TO CHECK THESE SIMULATANEOUSLY IN N QUERIES :(
    for(int i = 3; i <= n; i++) {
        if(ask(2 * i - 1, 2 * i)) {
            cout << "! " << 2 * i - 1 << endl;
            return;
        }
    }
    if(ask(1, 2) || ask(1, 3)) {
        cout << "! 1" << endl;
        return;
    }
    if(ask(2, 3)) {
        cout << "! 2" << endl;
        return;
    }
    cout << "! 4" << endl;
    return;
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}