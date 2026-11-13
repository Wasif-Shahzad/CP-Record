#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int bst = max({a, b, c});
    char req = (bst == a ? 'P' : (bst == b ? 'R' : 'S'));
    for(int i =0 ; i < a + b + c; i++) cout << req;
    cout << "\n";
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
