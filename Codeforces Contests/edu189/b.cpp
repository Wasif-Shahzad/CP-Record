//
// b.cpp
// Created by wasifshahzad on 04/21/26 at 19:39:10.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

// 01100
// 01010

void solve() {
    // flip if [l...r] is fine, pref is fine and suff is fine
    // s[l] = s[r + 1] and s[r] = s[l - 1]
    // reverse [l...r] works if pref[l - 1] is fine and suff[r + 1] is fine
    // and s[l] != s[r + 1]
    // and s[r] != s[l - 1]
    // and s[l...r] is fine
    string s;
    cin >> s;
    int n = s.size();
    vector<int> a(n);
    for(int i = 0; i < n; i++) a[i] = s[i] - 'a';
    int l = -1, r = -1;
    for(int i = 1; i < n; i++) {
        if(a[i] == a[i - 1]) {
            l = i;
            break;
        }
    } 
    if(l == -1) {
        cout << "YES\n";
        return;
    }
    for(int i = l + 1; i < n; i++) {
        if(a[i] == a[i - 1]) {
            r = i - 1;
            break;
        }
    }
    if(r == -1) {
        cout << "YES\n";
        return;
    }
    if(a[l] != a[r]) {
        reverse(a.begin() + l, a.begin() + r + 1);
    } else {
        for(int i = l; i <= r; i++) a[i] ^= 1;
        reverse(a.begin() + l, a.begin() + r + 1);
    }
    for(int i = 1; i < n; i++) {
        if(a[i] == a[i - 1]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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