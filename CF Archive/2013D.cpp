//
// 2013D.cpp
// Created by wasifshahzad on 05/17/26 at 15:17:00.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

void solve() {
    // binary search?
    // increase the current min till the second min
    // decrease the current max to second max
    // if a[i] is min, then we can go to (a[i - 1] + a[i]) / 2
    // if a[i] is max, we can go to (a[i] + a[i + 1]) / 2
    // sum stays preserved 
    // if we decrease a[i], then we can use that +1 in [i + 1, n]
    // ideally we want everyone to be around average
    // the only issue is that if we don't have enough extra in prefix of some element
    // in that case we try to reach the average in the suffix of that element
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    stack<pair<int, int>> s;
    s.push({a[0], 1});
    for(int i = 1; i < n; i++) {
        pair<int, int> cur = {a[i], 1};
        while(!s.empty()) {
            // x / y > a / b
            // x * b > a * y
            auto [x, y] = s.top();
            if(x * cur.second > cur.first * y) {
                s.pop();
                cur.first += x;
                cur.second += y;
            } else {
                break;
            }
        }
        s.push(cur);
    }
    int mn = 1e13, mx = 0;
    while(s.size()) {
        auto [x, y] = s.top();
        mn = min(mn, x / y);
        mx = max(mx, (x + y - 1) / y);
        s.pop();
    }
    cout << mx - mn << '\n';
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