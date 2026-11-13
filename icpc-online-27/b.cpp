#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 1e9+7, N = 1e6+5;
int fact[N], inv[N];
map<pair<int, int>, int> memo;

int power(int a, int b) {
    int ans = 1;
    while (b > 0) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return ans;
}

int modInverse(int x) {
    return power(x, mod - 2) % mod;
}

int ncr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * inv[r] % mod * inv[n - r] % mod;
}

void solve() {
    int n, f;
    cin >> n >> f;
    if (memo.count({n, f})) {
        cout << memo[{n, f}] << ' ';
        return;
    }
    int maxj = (n - 1) / 2;
    int fc = min(f, maxj);
    int ans = 0;
    if (fc + 1 <= maxj - fc + 1) {
        for(int i = 0; i <= fc; i++) {
            ans = (ans + ncr(n, 2 * i + 1)) % mod;
        }
    } else {
        int valid = power(2, n - 1);
        int sum = 0;
        for(int i = fc + 1; i <= maxj; i++) {
            sum = (sum + ncr(n, 2 * i + 1)) % mod;
        }
        ans = (valid - sum + mod) % mod;
    }
    memo[{n, f}] = ans;
    cout << ans << ' ';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    fact[0] = inv[0] = 1;
    for(int i = 1; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    inv[N - 1] = modInverse(fact[N - 1]) % mod;
    for(int i = N - 2; i > 0; i--) {
        inv[i] = (inv[i + 1] * (i + 1)) % mod;
    }
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    cout << '\n';
}
