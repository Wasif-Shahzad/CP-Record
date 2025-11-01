//
// g.cpp
// Created by Wasif on 10/18/25 at 06:41:52.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MAXN = 1001;
int occ[MAXN], rm = 0;
vector<pair<int, int>> g;

void buildSeq(vector<int> &a) {
    if(a.empty()) {
        return;
    }
    if(a.size() == 1) {
        occ[a[0] + rm] = a[0] + 1;
        return;
    }
    if(a.size() == 2) {
        occ[a[1] + rm] = a[0];
        occ[a[0] + rm] = a[1] + 1 - a[0];
        return;
    }
    int n = a.size();
    occ[a[n - 1] + rm] = a[0];
    occ[a[0] + rm] = a[n - 1] - a[n - 2];
    vector<int> b;
    rm += a[0];
    for(int i = 1; i + 1 < n; i++) {
        b.push_back(a[i] - a[0]);
    }
    buildSeq(b);
}

void buildGraph(vector<pair<int, int>>& a) {
    if(a.empty()) {
        return;
    }
    int mx = a.back().first;
    int n = a.size();
    for(int i = 0; i + 1 < n; i++) {
        g.push_back({a[i].second, a[n - 1].second});
        a[i].first--;
    }
    a.back().second = 0;
    vector<pair<int, int>> b;
    for(int i = 0; i + 1 < n; i++) {
        if(a[i].first == 0) continue;
        b.push_back({a[i].first, a[i].second});
    }
    sort(b.begin(), b.end());
    buildGraph(b);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> st(n);
    for(int i = 0; i < n; i++) {
        cin >> st[i];
    }
    buildSeq(st);
    vector<pair<int, int>> seq;
    int k = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < occ[st[i]]; j++) {
            seq.push_back({st[i], k++});
        }
    }
    buildGraph(seq);
    cout << g.size() << '\n';
    for(auto [u, v]: g) {
        cout << u + 1 << " " << v + 1 << '\n';
    }
}