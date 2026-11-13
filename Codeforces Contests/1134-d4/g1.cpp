#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int &i: a) cin >> i;
    int idx = max_element(a.begin(), a.end()) - a.begin();
    auto f = [&] (int x) -> bool {
        // our largest element doesn't change so we can use that as a pivot
        auto b = a;
        int sm = 0;
        for(int i = (idx - 1 + n) % n; i != idx; i = (i - 1 + n) % n) {
            int j = (i + 1) % n;
            if (abs(b[i] - b[j]) <= x) continue;
            if (b[i] < b[j]) {
                sm += b[j] - x - b[i];
                b[i] = b[j] - x;
            } else {
                sm += b[i] - x - b[j];
                b[j] = b[i] - x;
            }
        }
        for(int i = (idx + 1) % n; i != idx; i = (i + 1) % n) {
            int j = (i - 1 + n) % n;
            // cerr << i << " " << j << '\n';
            if (abs(b[i] - b[j]) <= x) continue;
            if (b[i] < b[j]) {
                sm += b[j] - x - b[i];
                b[i] = b[j] - x;
            } else {
                sm += b[i] - x - b[j];
                b[j] = b[i] - x;
            }
        }
        return sm <= k;
    };
    int lo = -1, hi = 0;
    for(int i = 0; i < n; i++) {
        hi = max(hi, abs(a[i] - a[(i + 1) % n]));
    }
    while (hi > lo + 1) {
        int mid = (hi + lo) / 2;
        if (f(mid)) hi = mid;
        else lo = mid;
    }
    cout << hi << '\n';
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
