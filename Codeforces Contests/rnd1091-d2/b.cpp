//
// b.cpp
// Created by wasifshahzad on 04/07/26 at 19:41:34.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    int j; cin >> j; j--;
    array<int, 2> ind{-1, -1};
    vector<int> nxt(n, -1), prev(n, -1);
    for(int i = n - 1; i >= 0; i--) {
        nxt[i] = ind[!a[i]];
        ind[a[i]] = i;
    }
    ind = {-1, -1};
    for(int i = 0; i < n; i++) {
        prev[i] = ind[!a[i]];
        ind[a[i]] = i;
    }
    int l = -1, r = -1;
    for(int i = 0; i < j; i++) {
        if(a[i] != a[j]) {
            l = i;
            break;
        }
    }
    for(int i = j; i < n; i++) {
        if(a[i] != a[j]) {
            r = i;
        }
    }
    int ans = 0;
    if(l != -1 && r != -1) {
        while(l < j && r > j) {
            ans += 2;
            l = nxt[l];
            r = prev[r];
            if(l == -1 || r == -1) break;
            l = nxt[l];
            r = prev[r];       
        }
    }
    if(l != -1) {
        while(l < j) {
            ans += 2;
            l = nxt[l];
            if(nxt[l] == -1) break;
            l = nxt[l];
        }
    }
    if(r != -1) {
        while(r > j) {
            ans += 2;
            r = prev[r];
            if(r == -1) break;
            r = prev[r];
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