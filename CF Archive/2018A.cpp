#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, k;
    cin >> n >> k;
    int s = 0;
    vector<int> a(n);
    for(int &i: a) {
        cin >> i;
        s += i;
    }
    auto f = [&] (int x) -> bool {
        int cnt = (s + x - 1) / x;
        return cnt * x - s <= k;
    };
    int lo = 1, hi = n + 1;
    while (hi > lo + 1) {
        int mid = (hi + lo) / 2;
        if (f(mid)) lo = mid;
        else hi = mid;
    }
    cout << lo << '\n';
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
