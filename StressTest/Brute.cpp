#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
#define int long long

string brute(vector<int> a, int k) {
    map<vector<int>, bool> dp;

    auto dfs = [&](auto&& self, vector<int>& a) -> bool {
        if (dp.count(a)) return dp[a];

        int n = a.size();

        for (int i = 0; i < n; i++) {
            if (a[i] == 0) continue;

            a[i]--;
            for (int j = max(0ll, i - k); j < i; j++)
                a[j]++;

            bool win = self(self, a);

            a[i]++;
            for (int j = max(0ll, i - k); j < i; j++)
                a[j]--;

            if (!win) return dp[a] = true;
        }

        return dp[a] = false;
    };

    return dfs(dfs, a) ? "Alice" : "Bob";
}

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int &i: a) cin >> i;
    cout << brute(a, k) << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
