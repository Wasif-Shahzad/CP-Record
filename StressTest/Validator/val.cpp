#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

void solve() {
    int n;
    cin >> n;
    vector<array<int, 4>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1] >> a[i][2];
        a[i][3] = i;
    }
    int gans;
    cin >> gans;
    vector<int> gorder;
    int k; cin >> k;
    gorder.resize(k);
    for(int i = 0; i < k ;i++) cin >> gorder[i];
    auto b = a;
    int ans = 0;
    vector<int> order;
    sort(a.begin(), a.end());
    do {
        int cur = 0;
        int t = 0;
        vector<int> o;
        for(int i = 0; i < n; i++) {
            if(t + a[i][0] >= a[i][1]) continue;
            cur += a[i][2];
            t += a[i][0];
            o.push_back(a[i][3]);
        }
        if(cur > ans) {
            ans = cur;
            order = o;
        }
    } while(next_permutation(a.begin(), a.end()));
    if(ans != gans) {
        cout << "Not optimal choice\n";
        return;
    }
    int can = 0, tt = 0;
    for(int i: gorder) {
        auto [t, d, p, j] = b[i - 1];
        if(tt + t < d) {
            tt += t;
            can += p;
        }
    }
    // cout << can << '\n';
    if(can != gans) {
        cout << "Invalid order\n";
        return;
    }
    cout << "OK\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}
