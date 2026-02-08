//
// b.cpp
// Created by wasifshahzad on 12/16/25 at 07:18:47.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> pos;
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        if(x < 0) pq.push(x);
        else pos.push_back(x);
    }
    while(pq.size() && k > 0) {
        int v = pq.top();
        pq.pop();
        pos.push_back(v * -1);
        k--;
    }
    while(pq.size()) {
        int v = pq.top();
        pq.pop();
        pos.push_back(v);
    }
    k &= 1;
    sort(pos.begin(), pos.end());
    if(k) {
        pos[0] *= -1;
    }
    int ans = 0;
    for(int i: pos) ans += i;
    cout << ans << '\n';
}