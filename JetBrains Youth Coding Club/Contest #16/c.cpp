#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

void solve() {
    int n = 14;
    vector<int> a(n);
    for(int &i: a) cin >> i;
    int ans = 0;
    for(int k = 0; k < 14; k++) {
        rotate(a.begin(), a.begin() + 1, a.end());
        auto b = a;
        int tmp = b[0] % 14, tot = b[0] / 14;
        for(int i = 1; i < 14; i++) {
            b[i] += tot;
            if(i <= tmp) b[i]++;
        }
        if(tot > 0) b[0] = tot;
        int here = 0;
        for(int i = 0; i < 14; i++) if(b[i] % 2 == 0) here += b[i];
        ans = max(ans, here);
    }
    cout << ans << '\n';
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
