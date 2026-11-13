#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5+5;
int isPrime[N], nxt[N], f[N], spf[N];

void solve() {
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i].first;
        f[a[i].first]++;
        a[i].second = i;
    }
    int req = 0, sum = 0;
    for(int i = 0; i < n; i++) {
        req += nxt[a[i].first] - a[i].first;
        sum += a[i].first;
    }
    if (req <= sum) {
        for(int i = 0; i < n; i++) {
            cout << nxt[a[i].first] << " ";
        }
        cout << '\n';
        return;
    }
    sort(a.begin(), a.end());
    a[0].first = nxt[a[0].first];
    for(int i = 1; i < n; i++) {
        bool bad = false;
        for(int j = 0; j < i; j++) {
            int g = __gcd(a[i].first, a[j].first);
            if (not (g == 1 || g == min(a[i].first, a[j].first))) {
                bad = true;
                break;
            }
        }
        if (!bad) continue;
        int p = nxt[a[i].first];
        int l = a[i].first;
        for(int j = 0; j < i; j++) {
            int g = __gcd(a[i].first, a[j].first);
            if (g == 1) continue;
            if (g == min(a[i].first, a[j].first)) continue;
            l = lcm(l, a[j].first);
            if (l >= p) break;
        }
        a[i].first = min(p, l);
    }
    vector<int> ans(n);
    for(int i = 0; i < n; i++) ans[a[i].second] = a[i].first;
    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for(int i = 2; i < N; i++) isPrime[i] = 1, spf[i] = i;
    for(int i = 2; i < N; i++) {
        if (isPrime[i]) {
            for(int j = 2 * i; j < N; j += i) {
                isPrime[j] = 0;
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
    int lst = -1;
    for(int i = N - 1; i >= 0; i--) {
        if (isPrime[i]) lst = i;
        if (lst == -1) continue;
        nxt[i] = lst;
    }
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
