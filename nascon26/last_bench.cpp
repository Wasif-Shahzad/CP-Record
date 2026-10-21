#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, w;
        cin >> n >> w;
        int lst = (n + w - 1) / w;
        if (lst % 2 == 0) {
            cout << w * (lst - 1) + 1 << '\n';
            continue;
        }
        if (lst == 1) {
            cout << n << '\n';
            continue;
        }
        int end = (n % w) + (n % w == 0 ? w : 0);
        if (end >= w - 1) {
            cout << n << '\n';
        } else {
            cout << (lst - 1) * w - w + 1 << '\n';
        }
    }
}
