#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mod = 998244353;
int fact(int x) {
    int res = 1;
    for(int i = 2; i <= x; i++) {
        res = res * i % mod;
    }
    return res;
}

int power(int a, int b) {
    int ans = 1;
    while (b > 0) {
        if (b & 1) ans = ans * a % mod;
        a = a * a % mod;
        b /= 2;
    }
    return ans;
}

int modinverse(int x) {
    return power(x, mod - 2) % mod;
}

int ncr(int n, int r) {
    int ans = fact(n);
    int inv = modinverse(fact(r));
    ans = ans * inv % mod;
    ans = ans * inv % mod;
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &i: a) cin >> i;
    int c = n / 3;
    int ans = ncr(c, c / 2);
    for(int i = 0; i < n; i += 3) {
        int mn = min({a[i], a[i + 1], a[i + 2]});
        int cnt = 0;
        for(int j: {0, 1, 2}) cnt += a[i + j] == mn;
        ans = ans * cnt % mod;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
}
