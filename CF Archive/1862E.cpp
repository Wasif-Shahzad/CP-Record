#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> a(n);
    for(int &i: a) cin >> i;
    priority_queue<int, vector<int>, greater<int>> pq;
    int sum = 0, ans = 0;
    for(int i = 0; i < n; i++) {
        if (a[i] <= 0) continue;
        if (i == 0) {
            pq.push(a[i]);
            sum += a[i];
        } else if(pq.size() < m) {
            pq.push(a[i]);
            sum += a[i];
        } else if (a[i] > pq.top()) {
            sum -= pq.top();
            pq.pop();
            sum += a[i];
            pq.push(a[i]);
        }
        ans = max(ans, sum - (i + 1) * d);
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
