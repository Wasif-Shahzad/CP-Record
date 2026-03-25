//
// b.cpp
// Created by wasifshahzad on 03/22/26 at 12:56:07.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &i: a) cin >> i;
    for(int i = 0; i < n; i++) {
        int sm = 0, lg = 0;
        for(int j = i + 1; j < n; j++) {
            sm += (a[j] < a[i]);
            lg += (a[j] > a[i]);
        }
        cout << max(sm, lg) << " ";
    }
    cout << '\n';
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