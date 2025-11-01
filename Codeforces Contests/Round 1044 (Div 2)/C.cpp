//
// C.cpp
// Created by wasifshahzad on 8/25/25 at 13:20:56.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int ask(int x, set<int> s) {
    assert(s.count(x));
    cout << "? " << x << " " << s.size() << " ";
    for (int v: s) cout << v << " ";
    cout << endl;
    int len; cin >> len;
    if (len == -1) {
        exit(0);
    }
    return len;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int mx = 0, k = -1;
        set<int> s;
        for (int i = 1; i <= n; i++) {
            s.insert(i);
        }
        vector<vector<int>> level(n + 1);
        for (int i = 1; i <= n; i++) {
            int cur = ask(i, s);
            if (cur > mx) {
                mx = cur;
                k = i;
            }
            level[cur].push_back(i);
        }
        // if after removing the path length disturbs then it is it
        // otherwise the last to be removed is it
        vector<int> path{k};
        for (int l = mx - 1; l > 0; l--) {
            auto tmp = level[l];
            int nxt = -1;
            while (tmp.size() > 0) {
                int v = tmp.back();
                tmp.pop_back();
                s.erase(v);
                int here = ask(k, s);
                if (here != mx) {
                    nxt = v;
                    break;
                }
            }
            path.push_back(nxt);
            for (int v : level[l]) {
                if (v == nxt) continue;
                if (s.count(v)) s.erase(v);
            }
            s.insert(nxt);
        }
        cout << "! " << mx << " ";
        for (int v: path) cout << v << " ";
        cout << endl;
    }
}