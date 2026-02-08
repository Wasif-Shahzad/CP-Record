//
// 3.cpp
// Created by wasifshahzad on 12/24/25 at 20:19:53.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

struct DSU{
    vector<int> size, par;
    int n, cmp;

    void init(int _n) {
        n = cmp = _n;
        size.assign(n, 1ll);
        par.resize(n);
        iota(par.begin(), par.end(), 0);
    }

    int find(int x) {
        if(x == par[x]) return x;
        return par[x] = find(par[x]);
    }

    void unite(int a, int b) {
        a = find(a), b = find(b);
        if(a != b) {
            if(size[a] < size[b]) swap(a, b);
            size[a] += size[b];
            par[b] = a;
            cmp--;
        }
    }
};

vector<int> solve1(vector<int>& a, bool print=true) {
    int n = a.size();
    vector<vector<int>> loc(n + 1);
    for(int i = 0; i < n; i++) {
        loc[a[i]].push_back(i);
    }
    DSU dsu;
    dsu.init(n);
    int bad = n;
    vector<int> ans(n + 1, -1);
    for(int i = n; i >= 0; i--) {
        for(int j: loc[i]) {
            if(j + 1 < n && a[j] <= a[j + 1]) {
                dsu.unite(j, j + 1);
            }
            if(j - 1 >= 0 && a[j] <= a[j - 1]) {
                dsu.unite(j, j - 1);
            }
        }
        bad -= (int)loc[i].size();
        ans[i] = dsu.cmp - bad;
    }
    if(print) {
        for(int i = 1; i <= n; i++) cout << ans[i] << " ";
        cout << '\n';
    }
    return ans;
}

void solve2() {
    int n;
    cin >> n;
    vector<int> a(n + 1, 1);
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    auto cmp = [&] (auto x, auto y) -> bool {
        return x.second - x.first < y.second - y.first;
    };
    set<pair<int, int>, decltype(cmp)> breakable(cmp);
    set<pair<int, int>> single;
    vector<int> ans(n, -1);
    breakable.insert({0, n - 1});
    if(a[1] != 1) {
        cout << -1 << '\n';
        return;
    }
    int cur = 1;
    for(int i = 2; i <= n; i++) {
        if(a[i] > a[i - 1]) {
            // need to break
            while(cur < a[i]) {
                if(breakable.empty()) {
                    cout << -1 << '\n';
                    return;
                }
                auto [l, r] = *breakable.begin();
                breakable.erase(*breakable.begin());
                int left = -1;
                for(int j = l + 1; j <= r; j += 2) {
                    ans[j] = i - 1;
                    single.insert({j - 1, j - 1});
                    cur++;
                    if(cur == a[i]) {
                        left = j + 1;
                        break;
                    }
                }
                l = left;
                if(r - l > 2) {
                    breakable.insert({l, r});
                } else {
                    single.insert({l, r});
                }
            }
        } else {
            // need to remove
            vector<pair<int, int>> nxt;
            while(cur > a[i]) {
                if(single.empty()) {
                    while(breakable.size()) {
                        auto [l, r] = *breakable.begin();
                        for(int j = l; j <= r; j++) {
                            ans[j] = i - 1;
                        }
                        breakable.erase(*breakable.begin());
                        cur--;
                        if(cur == a[i]) break;
                    }
                } else if(single.size()) {
                    while(single.size()) {
                        auto [l, r] = *single.begin();
                        if(r > l) {
                            nxt.push_back({r, r});
                            r = l;
                        }
                        for(int j = l; j <= r; j++) {
                            ans[j] = i - 1;
                        }
                        single.erase(*single.begin());
                        cur--;
                        if(cur == a[i]) break;
                    }
                } else break;
            }
            if(cur > a[i]) {
                cout << -1 << '\n';
                return;
            }
            for(auto [l, r]: nxt) {
                single.insert({l, r});
            }
        }
    }
    for(int i = 0; i < n; i++) {
        if(ans[i] == -1) ans[i] = n;
    }
    for(int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    if(t == 1) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        solve1(a);
    } else {
        solve2();
    }
}