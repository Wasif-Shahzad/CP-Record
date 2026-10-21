#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    string s;
    cin >> s;
    // r = g, g = b => r - g = g - b
    map<pair<int, int>, int> f;
    int r = 0, g = 0, b = 0;
    f[{0, 0}] = 1;
    int ans = 0;
    for(char i: s) {
        if (i == 'r') r++;
        else if(i == 'g') g++;
        else if(i == 'b') b++;
        ans += f[{r - g, g - b}];
        f[{r - g, g - b}]++;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
