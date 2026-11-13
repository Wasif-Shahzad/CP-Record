#include <bits/stdc++.h>
using namespace std;
// #define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // with prefix we can get the chain
    // then in our component we have to find the first element < l
    // we store each component, store the index of each element in its component
    // then binary search over distance from there
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for(int &i: a) cin >> i;
    vector<int> prev(n, -1);
    stack<int> s;
    #define LOG 24
    vector<array<int, LOG>> up(n);
    for(int i = 0; i < n; i++) {
        while (s.size() && a[s.top()] < a[i]) s.pop();
        if (s.size()) {
            prev[i] = s.top();
            up[i][0] = prev[i];
        } else {
            up[i][0] = -1;
        }
        s.push(i);
    }
    for(int i = 0; i < n; i++) {
        for(int j = 1; j < LOG; j++) {
            int prev = up[i][j - 1];
            if (prev == -1) up[i][j] = -1;
            else up[i][j] = up[prev][j - 1];
        }
    }
    while (q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int ans = 0;
        for(int i = LOG -1; i >= 0; i--) {
            if (up[r][i] >= l) {
                ans |= (1ll << i);
                r = up[r][i];
            }
        }
        cout << ans + 1 << '\n';
    }
}
