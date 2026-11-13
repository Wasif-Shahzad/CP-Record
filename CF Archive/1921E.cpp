#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, m, xa, ya, xb, yb;
    cin >> n >> m >> xa >> ya >> xb >> yb;
    if (xa >= xb) {
        cout << "Draw\n";
        return;
    }
    if ((xb - xa) & 1) {
        // Alice CAN win
        int moves = (xb - xa - 1) / 2;
        int r = min(m, yb + moves);
        int ar = min(m, ya + moves + 1);
        int l = max(1ll, yb - moves);
        int al = max(1ll, ya - moves - 1);
        if (al <= r && r <= ar && l >= al && l <= ar) {
            cout << "Alice\n";
        } else {
            cout << "Draw\n";
        }
    } else {
        int moves = (xb - xa) / 2;
        int r = min(m, ya + moves);
        int br = min(m, yb + moves);
        int l = max(1ll, ya - moves);
        int bl = max(1ll, yb - moves);
        if (bl <= r && r <= br && bl <= l && l <= br) {
            cout << "Bob\n";
        } else {
            cout << "Draw\n";
        }
    }
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
