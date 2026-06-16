//
// b.cpp
// Created by wasifshahzad on 04/08/26 at 19:39:21.
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
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    auto f = [&] (int x) -> bool {
        vector<int> b;
        int len = n - k;
        int req = len / 2;
        for(int i = 0; i < n; i++) {
            if(a[i] > x && req > 0) b.push_back(a[i]), req--;
        }
        req = (len - 1) / 2;
        for(int i = 0; i < n; i++) {
            if(a[i] < x && req > 0) b.push_back(a[i]), req--;
        }
        int rem = len - b.size();
        for(int i = 0; i < n; i++) {
            rem -= a[i] == x;
        }
        return rem <= 0;
    };
    vector<int> res;
    for(int i = 0; i < n; i++) {
        if(f(a[i])) res.push_back(a[i]);
    }
    sort(all(res));
    res.erase(unique(res.begin(), res.end()), res.end());
    for(int i: res) cout << i << " ";
    cout << '\n';
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