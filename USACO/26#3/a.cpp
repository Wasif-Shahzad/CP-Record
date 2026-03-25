//
// a.cpp
// Created by wasifshahzad on 02/21/26 at 13:08:59.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

/*
there will be cycles
i just don't know how to check if there's a cycle or not
it is doable in O(n^2)
we reach cycle quickly
*/

void solve() {
    int n, h;
    cin >> n >> h;
    vector<int> a(n + 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    vector<int> win(n + 1, 0);
    int k;
    cin >> k;
    for(int i = 0; i < k; i++) {
        int x;
        cin >> x;
        win[x] = 1;
    }
    priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq, orig;
    for(int i = 1; i <= h; i++) {
        pq.push({!win[i], a[i], i});
        orig.push({!win[i], a[i], i});
    }
    deque<int> q;
    for(int i = h + 1; i <= n; i++) q.push_back(i);
    
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}