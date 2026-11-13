#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int a, b;
    cin >> a >> b;
    if (a == b) {
        cout << 0 << '\n';
        return;
    }
    if (__gcd(a, b - a) == 1) {
        cout << 1 << '\n' << b - a << '\n';
        return;
    }
    for(int i = b - 1; i >= max(b - 4096, a + 1); i--) {
        if (__gcd(a, i) == 1 && __gcd(b, i) == 1) {
            cout << 2 << '\n';
            cout << i - a << " " << b - i << '\n';
            return;
        }
    }
    const int m = b - a;
    vector<int> dist(m + 1, -1), par(m + 1, -1);
    queue<int> q;
    dist[0] = 0;
    q.push(a);
    while (!q.empty()) {
        int ca = q.front();
        q.pop();
        if (ca == b) break;
        for(int v = ca + 1; v <= b; v++) {
            if (dist[v - a] == -1 && __gcd(v, ca) == 1) {
                dist[v - a] = dist[ca - a] + 1;
                par[v - a] = ca;
                q.push(v);
            }
        }
    }
    vector<int> path;
    int cur = b;
    while (cur != a) {
        int p = par[cur - a];
        path.push_back(cur - p);
        cur = p;
    }
    cout << path.size() << '\n';
    reverse(path.begin(), path.end());
    for(int p: path) cout << p << " ";
    cout << '\n';
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
