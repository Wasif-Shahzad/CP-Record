#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

void solve() {
    int n;
    cin >> n;
    vector<array<int, 4>> a;
    for(int i = 0; i < n; i++) {
        int t, d, p;
        cin >> t >> d >> p;
        if(t >= d) continue;
        a.push_back({t, d, p, i});
    }
    sort(all(a), [&] (array<int, 4> x, array<int, 4> y){
        if(x[1] != y[1]) return x[1] < y[1];
        return x[0] < y[0];
    });
    n = (int)a.size();
    // dp[i][j] => dp[i + 1][j + t[i]] + p[i]
    // dp[i][j] => dp[i + 1][j]
    const int M = 2005;
    vector<vector<int>> dp(n + 1, vector<int>(M, 0));
    for(int i = n - 1; i >= 0; i--) {
        for(int j = 0; j < M; j++) {
            if(j + a[i][0] < a[i][1]) {
                dp[i][j] = dp[i + 1][j + a[i][0]] + a[i][2];
            }
            dp[i][j] = max(dp[i][j], dp[i + 1][j]);
        }
    }
    int ans = *max_element(all(dp[0]));
    vector<int> ord;
    int cur = ans, prev = 0;
    for(int i = 0; i < n; i++) {
        for(int j = prev; j < M; j++) {
            if(j + a[i][0] < a[i][1] && dp[i][j] == cur && dp[i + 1][j + a[i][0]] == cur - a[i][2]) {
                cur -= a[i][2];
                ord.push_back(a[i][3]);
                prev += a[i][0];
                break;
            }
        }
    }
    cout << ans << '\n';
    cout << (int)ord.size() << '\n';
    for(int i: ord) cout << i + 1 << " ";
    cout << '\n';
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

