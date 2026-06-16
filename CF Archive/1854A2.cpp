//
// 1854A2.cpp
// Created by wasifshahzad on 04/18/26 at 11:22:40.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

/*
either need all negative or all positive
then n - 1 ops
try both ig
*/

void solve() {
    int n;
    cin >> n;
    vector<array<int, 3>> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i][0];
        a[i][1] = (a[i][0] >= 0);
        a[i][2] = i;
    }
    sort(all(a), [](auto x, auto y) {
        if(abs(x[0]) != abs(y[0])) return abs(x[0]) < abs(y[0]);
        return x[1] < y[1];
    });
    vector<pair<int, int>> pos, neg;
    {
        auto b = a;
        vector<int> c(n);
        if(b[n - 1][1] == 1) {
            for(int i = n - 2; i >= 0; i--) {
                if(!b[i][1]) {
                    b[i][0] += b[n - 1][0];
                    pos.push_back({b[i][2], b[n - 1][2]});
                }
            }
        } else {
            int j = -1;
            for(int i = n - 2; i >= 0; i--) {
                if(b[i][1] && b[i][0] > 0) {
                    j = i;
                    break;
                }
            }
            if(j != -1) {
                auto [x, p, k] = b[j];
                while(x < abs(b[n - 1][0])) {
                    pos.push_back({k, k});
                    x += x;
                }
                b[j][0] = x;
                for(int i = n - 1; i >= 0; i--) {
                    if(!b[i][1]) {
                        pos.push_back({b[i][2], k});
                        b[i][0] += x;
                    }
                }
            }
        }
        for(int i = 0; i < n; i++) {
            c[b[i][2]] = b[i][0];
        }
        if(*min_element(all(c)) >= 0) {
            int pref = c[0];
            cerr << "Prefix sum: " << pref << " ";
            for(int i = 1; i < n; i++) {
                if(c[i] >= pref) pref = c[i];
                else {
                    pos.push_back({i, i - 1});
                    pref += c[i];
                }
                cerr << pref << " ";
            }
            cerr << '\n';
        }
    }
    {
        auto b = a;
        vector<int> c(n);
        if(b[n - 1][1] == 0) {
            for(int i = n - 2; i >= 0; i--) {
                if(b[i][1] && b[i][0] > 0) {
                    b[i][0] += b[n - 1][0];
                    neg.push_back({b[i][2], b[n - 1][2]});
                }
            }
        } else {
            int j = -1;
            for(int i = n - 2; i >= 0; i--) {
                if(!b[i][1]) {
                    j = i;
                    break;
                }
            }
            if(j != -1) {
                auto [v, p, k] = b[j];
                while(abs(v) < b[n - 1][0]) {
                    v += v;
                    neg.push_back({k, k});
                }
                b[j][0] = v;
                for(int i = n - 1; i >= 0; i--) {
                    if(b[i][1] && b[i][0] > 0) {
                        neg.push_back({b[i][2], k});
                        b[i][0] += v;
                    }
                }
            }
        }
        for(int i = 0; i < n; i++) {
            c[b[i][2]] = b[i][0];
        }
        if(*max_element(all(c)) <= 0) {
            int suff = c[n - 1];
            for(int i = n - 2; i >= 0; i--) {
                if(c[i] <= suff) suff = c[i];
                else {
                    suff += c[i];
                    neg.push_back({i, i + 1});
                }
            }
        }
    }
    cerr << "dbg: " << pos.size() << " " << neg.size() << '\n';
    if(pos.size() > neg.size()) swap(pos, neg);
    if(pos.empty()) swap(pos, neg);
    assert((int)pos.size() <= 31);
    cout << pos.size() << '\n';
    for(auto [i, j]: pos) cout << i + 1 << " " << j + 1 << '\n';
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