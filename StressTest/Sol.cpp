#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    /*
     * we add min(i, k - 1) stones to the total
     * at the end alice will want even stones in the first pile
     */
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int &i: a) cin >> i;
    vector<int> dist(n);
    int sum = 0, our = 0;
    for(int i = 0; i < k; i++) {
        dist[i] = i + 1;
        our += dist[i];
        sum += dist[i] * a[i];
    }
    for(int i = k; i < n; i++) {
        dist[i] = our + 1;
        our -= dist[i - k];
        our += dist[i];
        sum += dist[i] * a[i];
    }
    cout << ((sum & 1) ? "Alice" : "Bob") << '\n';
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
