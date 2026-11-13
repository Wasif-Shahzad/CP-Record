#include <bits/stdc++.h>
using namespace std;
#define int long long

/*
 * -2 9 11 18
 * cp = [0, 1, 2, 1]
 * cn = [1, 2, 1, 0]
 */

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &i: a) cin >> i;
    sort(a.begin(), a.end());
    vector<int> b;
    b.push_back(0);
    for(int i = 0; i < n; i++) {
        int j = i;
        while (j + 1 < n && a[j] == a[i]) j++;
        b.push_back(j - i + 1);
        i = j;
    }
    int m = b.size();
    vector<int> pref(m + 1, 0), suff(m + 2, 0);
    for(int i = 1; i <= m; i++) pref[i] = b[i] + pref[i - 1];
    for(int i = m; i >= 0; i--) suff[i] = b[i] + suff[i + 1];
    vector<int> cn(m + 1), cp(m + 1);
    for(int i = 1; i <= m; i++) {
        cn[i] = min(pref[i], suff[i + 1]);
        cp[i] = min(pref[i - 1], suff[i]);
    }
    pref.assign(m + 1, 0);
    suff.assign(m + 2, 0);
    for(int i = 1; i <= m; i++) pref[i] = pref[i - 1] + cn[i];
    for(int i = m; i >= 0; i--) suff[i] = suff[i + 1] + cp[i];
    #define oo 8e18
    int cost = oo, moves = oo;
    for(int i = 1; i <= m; i++) {
        int cost_here = pref[i - 1] + suff[i + 1];
        int moves =
    }
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
