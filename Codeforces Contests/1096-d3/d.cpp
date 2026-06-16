//
// d.cpp
// Created by wasifshahzad on 04/30/26 at 19:56:07.
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
    n *= 2;
    vector<int> a(n);
    int l = -1, r = -1;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        if(a[i] == 0) {
            if(l == -1) l = i;
            else r = i;
        }
    }
    bool f = true;
    for(int i = l + 1; i < r; i++) {
        int j = r - i + l;
        if(a[i] != a[j]) {
            f = false;
            break;
        }
    }
    int ans = 1;
    int x = l, y = r;
    auto process = [&] (int l, int r, bool flag=true) -> int {
        if(flag) {
            while(l > 0 && r + 1 < n) {
                if(a[l - 1] == a[r + 1]) l--, r++;
                else break;
            }
        }
        set<int> s;
        for(int i = l; i <= r; i++) s.insert(a[i]);
        int cans = 0;
        while(s.count(cans)) cans++;
        return cans;
    };
    if(f) {
        ans = max(ans, process(x, y));
    }
    ans = max(ans, process(x, x));
    ans = max(ans, process(y, y));
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