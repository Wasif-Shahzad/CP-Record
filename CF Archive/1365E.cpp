//
// 1365E.cpp
// Created by wasifshahzad on 04/10/26 at 20:15:12.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

/*
10001
00011
00101
01001
*/

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if(n == 1) {
        cout << a[0] << '\n';
        return;
    }
    int prs = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            prs = max(prs, a[i] | a[j]);
        }
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(i == j) continue;
            for(int k = 0; k < n; k++) {
                if(i == k || j == k) continue;
                prs = max(prs, a[i] | a[j] | a[k]);
            }
        }
    }
    cout << prs << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}