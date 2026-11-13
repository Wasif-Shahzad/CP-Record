#include <bits/stdc++.h>
using namespace std;
#define int long long

int count(int n, int j) {
    int p = 1ll << j;
    return ((n + 1) / (2 * p)) * p + max(0LL, (n + 1) % (2 * p) - p);
}

void solve() {
    // int n = 10, cur = 0;
    // for(int i = 1; i <= n; i++) {
    //     cur |= i;
    //     cout << i << ": \n";
    //     for(int mask = 0; mask < (1 << i); mask++) {
    //         int here = 0;
    //         for(int j = 0; j < i; j++) {
    //             if ((1 << j) & mask) {
    //                 here ^= 2 * (j + 1);
    //             } else {
    //                 here ^= (j + 1);
    //             }
    //         }
    //         if (here >= 2 * cur) {
    //             for(int j = 0; j < i; j++) {
    //                 cout << (((1 << j) & mask) > 0) << " ";
    //             }
    //             cout << '\n';
    //             break;
    //         }
    //     }
    // }
    int n;
    cin >> n;
    int cur = 1, p = 0;
    while (cur * 2 <= n) cur *= 2, p++;
    vector<int> ans(n + 1, 0);
    ans[cur] = 1, p--, cur /= 2;
    while (p >= 0) {
        int f = ans[2 * cur];
        int cnt = count(n, p + 1) - f;
        if (cnt % 2 == 0) {
            ans[cur] = 1;
        }
        cur /= 2;
        p--;
    }
    for(int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
