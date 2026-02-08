//
// 1534D.cpp
// Created by wasifshahzad on 01/04/26 at 11:51:16.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

int n;

vector<int> ask(int v) {
    cout << "? " << v << endl;
    vector<int> resp(n);
    for(int &i: resp) cin >> i;
    return resp;
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    vector<pair<int, int>> ans;
    cin >> n;
    vector<int> vis(n + 1, 0);
    vector<int> c = ask(1);
    vector<int> clr(n);
    vis[0] = 1;
    int w = 0, b = 0;
    for(int i = 0; i < n; i++) {
        clr[i] = c[i] & 1;
        w += clr[i] == 0;
        b += clr[i] == 1;
    }
    if(w <= b) {
        for(int i = 0; i < n; i++) {
            clr[i] ^= 1;
        }
    }
    for(int i = 0; i < n; i++) if (c[i] == 1) {
        ans.push_back({0, i});
    }
    for(int i = 1; i < n; i++) {
        if(clr[i] == 1) {
            auto res = ask(i + 1);
            for(int j = 0; j < n; j++) {
                if(vis[j]) continue;
                if(res[j] == 1) ans.push_back({j, i});
            }
            vis[i] = 1;
        }
    }
    cout << "!" << endl;
    for(auto [u, v]: ans) cout << u + 1 << " " << v + 1 << endl;
}