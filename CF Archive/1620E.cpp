//
// 1620E.cpp
// Created by wasifshahzad on 9/6/25 at 12:20:46.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int q;
    cin >> q;
    vector<vector<int>> pos(5e5 + 1);
    int i = 0;
    while(q--) {
        int t;
        cin >> t;
        if(t == 1) {
            int x;
            cin >> x;
            pos[x].push_back(i++);
        } else {
            int x, y;
            cin >> x >> y;
            if(x != y) {
                if(pos[x].size() > pos[y].size()) pos[x].swap(pos[y]);
                for(auto& j: pos[x]) pos[y].push_back(j); 
                pos[x].clear();
            }
        }
    }
    vector<int> ans(i);
    for(i = 1; i <= 5e5; i++) {
        for(int j: pos[i]) {
            ans[j] = i;
        }
    }

    for(int &x: ans) cout << x << " ";
    cout << '\n';
}