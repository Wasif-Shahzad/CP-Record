//
// c.cpp
// Created by wasifshahzad on 01/03/26 at 12:52:34.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int q;
    cin >> q;
    while(q--) {
        int k;
        cin >> k;
        int ans = 0;
        int l = -1, sum = 0, cnt = 0;
        for(int r = 0; r < n; r++) {
            sum += a[r];
            cnt += s[r] == 'E';
            while(sum > k && l + 1 <= r) {
                sum -= a[l + 1];
                cnt -= s[l + 1] == 'E';
                l++;
            }
            ans = max(ans, cnt);
        }
        cout << ans << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while(T--) {
        solve();
    }
}