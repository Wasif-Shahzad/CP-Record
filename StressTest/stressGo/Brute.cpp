//
// 449B.cpp
// Created by wasifshahzad on 06/23/26 at 18:50:17.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int &i: a) cin >> i;
    auto med = [&] (int l, int r) -> int {
        vector<int> cur;
        for(int i = l; i <= r; i++) {
            cur.push_back(a[i]);
        }
        sort(all(cur));
        int i = (r - l + 2) / 2;
        return cur[i - 1];
    };
    if (n == 1 && a[0] == k) {
        cout << "Yes\n";
        return;
    }
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if (med(i, j) == k) {
                cout << "Yes\n";
                return;
            }
        }
    }
    cout << "No\n";
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
