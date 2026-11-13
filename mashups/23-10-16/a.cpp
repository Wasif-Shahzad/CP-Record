#include <bits/stdc++.h>
using namespace std;
#define int long long

bool isPrime(int n) {
    if (n <= 1) return false;
    for(int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int find(int x) {
    for(int i = x; ; i++) {
        if (isPrime(i)) return i;
    }
}

void solve() {
    int n, m;
    cin >> n >> m;
    int prime = find(n - 1);
    cout << prime << " " << prime << '\n';
    for(int i = 1; i + 1 < n; i++) {
        cout << i << " " << i + 1 << " " << 1 << '\n';
    }
    cout << n - 1 << " " << n << " " << prime - (n - 2) << '\n';
    m -= n - 1;
    int i = 1, j = 3;
    while (m > 0) {
        cout << i << " " << j << " 1000000000\n";
        m--;
        j++;
        if (j > n) {
            i++;
            j = i + 2;
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}
