#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

void solve() {
    string s;
    cin >> s;
    int n;
    cin >> n;
    vector<string> a(n);
    vector<int> f(26, 0);
    bool found = false;
    for(int i = 0; i < n; i++) {
        string t; cin >> t;
        a[i] = t;
        if(t == s) {
            found = true;
        }
        f[t[0] - 'a']++;
    }
    if(found) {
        cout << "YES\n";
        return;
    }
    for(int i = 0; i < n; i++) {
        if(a[i][1] == s[0]) {
            if(f[s[1] - 'a']) {
                cout << "YES\n";
                return;
            }
        }
    }
    cout << "NO\n";
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
