//
// 1303D.cpp
// Created by wasifshahzad on 04/23/26 at 19:41:37.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

void solve() {
    int n, m;
    cin >> m >> n;
    vector<int> a(n);
    vector<int> f(34, 0);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        f[(int)__lg(a[i])]++;
    }
    if(accumulate(all(a), 0ll) < m) {
        cout << -1 << '\n';
        return;
    }
    int ans = 0;
    for(int i = 0; i < 31; i++) {
        if(m & (1ll << i)) {
            int k = -1;
            if(f[i]) f[i]--;
            else {
                for(int j = i + 1; j < 31; j++) {
                    if(f[j]) {
                        k = j;
                        break;
                    }
                }
                ans += k - i;
                f[k]--;
                i = k - 1;
            }
        }
        f[i + 1] += f[i] / 2;
    }
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