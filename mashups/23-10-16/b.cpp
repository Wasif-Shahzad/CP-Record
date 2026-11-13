#include <bits/stdc++.h>
using namespace std;
#define int long long

void simplify(pair<int, int>& f) {
    if (f.first == 0) {
        f.second = 1;
        return;
    }
    int g = __gcd(f.first, f.second);
    f.first /= g;
    f.second /= g;

    if (f.first < 0 && f.second < 0) {
        f.first = -f.first;
        f.second = f.second;
    } else if(f.second < 0) {
        f.first = -f.first;
        f.second = -f.second;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    #define oo 1e15
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(m);
    for(int i = 0; i < m; i++) {
        cin >> a[i].first >> a[i].second;
    }
    vector<int> ans(n + 1, 1);
    for(int i = 0; i < m; i++) {
        for(int j = i + 1; j < m; j++) {
            auto [xi, yi] = a[i];
            auto [xj, yj] = a[j];
            if (yi == yj) continue;
            int num = yi * xj - yj * xi;
            if (num % (yi - yj) != 0) continue;
            int k = num / (yi - yj);
            if (k >= 1 && k <= n) {
                int cnt = 0;
                for(int t = 0; t < m; t++) {
                    // y[i] / (x[i] - k) = y[j] / (x[j] - k)
                    // y[i] * (x[j] - k) = y[j] * (x[i] - k)
                    auto [xk, yk] = a[t];
                    if (yi * (xk - k) == yk * (xi - k)) cnt++;
                }
                ans[k] = max(ans[k], cnt);
            }
        }
    }
    int res = accumulate(ans.begin(), ans.end(), 0ll)-1;
    cout << res << '\n';
}
