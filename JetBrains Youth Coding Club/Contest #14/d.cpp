#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n), b(m);
    for(int &i: a) cin >> i;
    for(int &i: b) cin >> i;
    vector<int> type(k + 1, 0);
    for(int i: a) if(i <= k) type[i] = 1;
    for(int i: b) {
        if(i > k) continue;
        if(type[i] == 0) type[i] = 3;
        else if(type[i] == 1) type[i] = 2;
    }
    int sp1 = 0, sp2 = 0;
    for(int i = 1; i <= k; i++) {
        if(type[i] == 0) {
            //cout << i << '\n';
            cout << "No\n";
            return;
        }
        sp1 += (type[i] == 1);
        sp2 += (type[i] == 3);
    }
    if(sp1 > k / 2 || sp2 > k / 2) cout << "No\n";
    else cout << "Yes\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}
