//
// c.cpp
// Created by wasifshahzad on 05/30/26 at 17:12:20.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int &i: a) cin >> i;
    for(int &i: b) cin >> i;
    sort(all(a)); 
    sort(all(b));
    int i = n - 1, j = m - 1;
    int ans = 0;
    while(i >= 0 && j >= 0) {
        if(b[j] <= 2 * a[i]) {
            i--, j--;
            ans++;
        } else {
            j--;
        }
    }
    cout << ans << '\n';
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