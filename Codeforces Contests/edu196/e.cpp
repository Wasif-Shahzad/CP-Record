/*
 * only two pairs can have the adjacent condition.
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 998244353;
int bell[5001], fact[5001], inv[5001];

int pw(int a, int b) {
    int ans = 1;
    while (b > 0) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return ans;
}

int inverse(int x) {
    return pw(x, mod - 2) % mod;
}

int ncr(int n, int r) {
    if (r < 0 || r > n) return 0;
    int ans = fact[n];
    ans = ans * inv[n - r] % mod;
    ans = ans * inv[r] % mod;
    return ans;
}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> sizes;
    vector<char> cor;
    for(int i = 0; i < n; i++) {
        int j = i;
        while (j + 1 < n && s[j + 1] == s[i]) j++;
        sizes.push_back(j - i + 1);
        i = j;
        cor.push_back(s[i]);
    }
    int mx = n;
    int zr = 0, on = 0;
    if (sizes.size() > 1) {
        mx++;
        if (sizes[0] > 1) {
            if (cor[0] == '0') zr += sizes[0] - 1;
            else on += sizes[0] - 1;
        }
        for(int i = 1; i < sizes.size(); i++) {
            sizes[i]--;
            mx++;
            if (sizes[i] > 0 && i + 1 < sizes.size()) {
                sizes[i]--;
                mx++;
            }
            if (sizes[i] > 0) {
                if (cor[i] == '0') zr += sizes[i];
                else on += sizes[i];
            }
        }
    }
    int ans = bell[zr];
    ans = ans * bell[on] % mod;
    int m = sizes.size();
    if (m == 1) {
        cout << mx << " " << bell[n] << '\n';
        return;
    }
    vector<int> dp(m + 4, 0);
    dp[m] = 1;
    for(int i = m - 1; i >= 0; i--) {
        dp[i] = (dp[i + 2] + dp[i + 3]) % mod;
    }
    ans = ans * dp[0] % mod;
    cout << mx << " " << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fact[0] = 1, inv[0] = 1;
    for(int i = 1; i <= 5000; i++) {
        fact[i] = fact[i - 1] * i % mod;
        inv[i] = inverse(fact[i]);
    }
    bell[0] = 1;
    for(int i = 1; i <= 5000; i++) {
        for(int j = 0; j < i; j++) {
            int opt = ncr(i - 1, j);
            opt = opt * bell[j] % mod;
            bell[i] = (bell[i] + opt) % mod;
        }
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
