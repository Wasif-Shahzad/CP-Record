//
// a.cpp
// Created by wasifshahzad on 03/16/26 at 19:25:23.
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
    string s;
    cin >> s;
    vector<int> freq(n, 0);
    freq[0] = 1;
    int j = 0;
    for(int i = 0; i < n; i++) {
        if(s[j] == 'L') {
            freq[--j]++;
        } else {
            freq[++j]++;
        }
    }
    cout << n - count(all(freq), 0) << '\n';
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