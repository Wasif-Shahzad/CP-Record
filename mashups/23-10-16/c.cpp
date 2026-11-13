#include <bits/stdc++.h>
using namespace std;
// #define int long long

vector<int> ta(1e5 + 1), tb(1e5 + 1);

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> b[i];
    }
    vector<int> brk = {0, n};
    auto check = [&] (int x) -> bool {
        bool res = true;
        for(int i = 0; i + 1 < (int)brk.size(); i++) {
            int l = brk[i], r = brk[i + 1];
            int cntA = 0, cntB = 0;
            for(int j = l; j < r; j++) {
                if ((1ll << x) & a[j]) cntA++;
                if ((1ll << x) & b[j]) cntB++;
            }
            res &= (r - l - cntA == cntB);
        }
        return res;
    };
    auto add = [&] (int x) -> void {
        vector<int> new_brk = {};
        for(int i = 0; i + 1 < (int)brk.size(); i++) {
            int l = brk[i], r = brk[i + 1];
            int cntA = 0;
            for(int j = l; j < r; j++) {
                if ((1ll << x) & a[j]) cntA++;
            }
            int ak = l, bk = l;
            for(int j = 0; j < r - l; j++) {
                ta[j] = a[l + j];
                tb[j] = b[l + j];
            }
            for(int j = 0; j < r - l; j++) {
                if ((1ll << x) & ta[j]) a[ak++] = ta[j];
                if (not ((1ll << x) & tb[j])) b[bk++] = tb[j];
            }
            for(int j = 0; j < r - l; j++) {
                if (not ((1ll << x) & ta[j])) a[ak++] = ta[j];
                if ((1ll << x) & tb[j]) b[bk++] = tb[j];
            }
            new_brk.push_back(l);
            if (cntA > 0) new_brk.push_back(l + cntA);
        }
        new_brk.push_back(n);
        brk = new_brk;
    };
    int ans = 0;
    for(int i = 30; i >= 0; i--) {
        if (check(i)) {
            ans += (1ll << i);
            add(i);
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
