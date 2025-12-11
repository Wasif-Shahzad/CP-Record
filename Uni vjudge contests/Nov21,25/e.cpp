//
// e.cpp
// Created by Wasif on 11/21/25 at 21:17:26.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

struct Data{
    int s1, s2, s3;
    string name;
};

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<Data> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i].name >> a[i].s1 >> a[i].s2 >> a[i].s3;
        }
        sort(a.begin(), a.end(), [&] (Data x, Data y) {
            if(x.s3 != y.s3) return x.s3 > y.s3;
            if(x.s2 != y.s2) return x.s2 > y.s2;
            return x.s1 > y.s1;
        });
        bool has = false;
        for(int i = 0; i < m; i++) {
            if(a[i].name == s) {
                has = true;
                break;
            }
        }
        cout << (has ? "YA" : "TIDAK") << '\n';
    }
}