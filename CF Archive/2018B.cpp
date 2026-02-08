//
// 2018B.cpp
// Created by wasifshahzad on 12/30/25 at 15:07:02.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> a(n), mnLoc(n + 1, n + 10), mxLoc(n + 1, -1);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(mnLoc[a[i]] > n) mnLoc[a[i]] = i;
            mxLoc[a[i]] = i;
        }
        vector<int> l(n, 0), r(n, 0);
        for(int i = 0; i < n; i++) {
            l[max(0ll, i - a[i] + 1)]++;
            r[min(n - 1, i + a[i] - 1)]++;
        }
        int cur = 0, ans = 0;
        for(int i = 0; i < n; i++) {
            cur += l[i];
            ans += cur == n;
            cur -= r[i];
        }
        if(ans == 0) {
            cout << 0 << '\n';
            continue;
        }
        for(int t = 2; t <= n; t++) {
            mnLoc[t] = min(mnLoc[t], mnLoc[t - 1]);
            mxLoc[t] = max(mxLoc[t], mxLoc[t - 1]);
        }
        bool bad = false;
        for(int t = 1; t <= n; t++) {
            int L = mnLoc[t], R = mxLoc[t];
            if(R == -1) continue;
            if(R - L + 1 > t) {
                bad = true;
                break;
            }
        }
        if(bad) ans = 0;
        cout << ans << '\n';
    }
}