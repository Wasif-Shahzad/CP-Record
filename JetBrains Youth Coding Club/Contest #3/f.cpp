//
// f.cpp
// Created by Wasif on 10/19/25 at 10:37:36.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int pc[205], n;
vector<vector<int>> pre(205);

int solve(int start) {
    int begin = pc[start];
    vector<bool> done(n, false);
    int ans = 0, cur = begin, i = 0;
    while(true) {
        int sm = 0;
        for(int j = 0; j < n; j++) sm += (int)done[j];
        if(sm == n) break;
        for(int j = 0; j < n; j++) {
            if(pc[j] != cur) continue;
            if(done[j]) continue;
            bool good = true;
            for(int k: pre[j]) {
                if(!done[k] && pc[k] != cur) {
                    good = false;
                    break;
                } else if(!done[k]) {
                    queue<int> q;
                    q.push(k);
                    bool finish = true;
                    while(q.size()) {
                        int u = q.front();
                        q.pop();
                        for(int k: pre[u]) {
                            if(!done[k] && pc[k] != cur) {
                                finish = false;
                                break;
                            } else if(!done[k]) {
                                q.push(k);
                            }
                        }
                    }
                    if(!finish) {
                        good = false;
                        break;
                    }
                }
            }
            if(good) {
                done[j] = true;
            } 
            ans = max(ans, i);
        }
        if(cur == 3) cur = 1;
        else cur++;
        i++;
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> pc[i];
    }
    for(int i = 0; i < n; i++) {
        int k; cin >> k;
        for(int j = 0; j < k; j++) {
            int u;
            cin >> u;
            u--;
            pre[i].push_back(u);
        }
    }
    int ans = n, extra = 1e9, j = -1;
    for(int i = 0; i < n; i++) {
        if(pre[i].size() == 0) {
            extra = min(extra, solve(i));
        }
    }
    cout << ans + extra << '\n';
}