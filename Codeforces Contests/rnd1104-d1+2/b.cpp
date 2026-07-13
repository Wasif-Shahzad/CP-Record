//
// b.cpp
// Created by wasifshahzad on 06/18/26 at 19:39:42.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int &i: a) cin >> i;
    for(int &i: b) cin >> i;
    vector<int> mp(n, -1);
    set<pair<int, int>> s;
    for(int i = 0; i < n; i++) s.insert({b[i], i});
    vector<int> marked(n, 0);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(marked[j]) continue;
            if(b[j] >= a[i]) {
                mp[i] = j;
                marked[j] = true;
                break;
            }
        }
    }
    if(*min_element(all(mp)) == -1) {
        cout << -1 << '\n';
        return;
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(mp[j] < mp[i]) ans++;
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}