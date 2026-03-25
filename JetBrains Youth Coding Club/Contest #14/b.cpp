#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

void solve() {
    int n, k;
    cin >> n >> k;
    const int N = 1e5;
    vector<int> spf(N + 1);
    iota(all(spf), 0);
    for(int i = 2; i <= N; i++) {
        if(spf[i] == i) {
            for(int j = 2 * i; j <= N; j += i) {
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
    vector<int> ans;
    while(ans.size() < k) {
        int v = spf[n];
        if(ans.size() + 1 < k) ans.push_back(v);
        else ans.push_back(n);
        n /= v;
        if(n == 1) break;
    }
    if(ans.size() != k) cout << -1 << '\n';
    else {
        for(int i: ans) cout << i << " ";
        cout << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
}
