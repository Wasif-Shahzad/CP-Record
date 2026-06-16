//
// e.cpp
// Created by wasifshahzad on 04/30/26 at 20:11:59.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

void solve() {
    // if we're at index i coming from right to left and cubes above height j are free
    // then on the next move we will have [min(j, ai), n] free i.e. j = min(j, a[i])
    // j is basically suffix minimum
    // max(0, a[i] - suff[i]) move 
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<int> suff(n);
    suff[n - 1] = a[n - 1];
    for(int i = n - 2; i >= 0; i--) {
        suff[i] = min(suff[i + 1], a[i]);
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        ans += max(0ll, a[i] - suff[i]);
    }
    int cnt = 1, cur = suff[0];
    int oans = ans;
    for(int i = 1; i < n; i++) {
        if(suff[i] != cur) {
            int here = oans + cnt - 1;
            ans = max(ans, here);
            cnt = 1, cur = suff[i];
        } else cnt++;
    }
    ans = max(oans + cnt - 1, ans);
    cout << ans << '\n';
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