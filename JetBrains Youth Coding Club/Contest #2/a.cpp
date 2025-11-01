//
// a.cpp
// Created by Wasif on 10/11/25 at 09:53:44.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<string> a(n);
    bool bad = false;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        set<char> cur;
        for(int j: a[i]) cur.insert(j);
        if(cur.size() > 1) {
            bad = true;
        }
    }
    if(bad) {
        cout << "NO\n";
        return 0;
    }
    for(int i = 0; i + 1 < n; i++) {
        if(a[i][0] == a[i + 1][0]) {
            bad = true;
            break;
        }
    }
    cout << (bad ? "NO" : "YES") << '\n';
}