//
// a1.cpp
// Created by Wasif on 11/03/25 at 19:39:08.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string run;
    cin >> run;
    if(run == "first") {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            cout << char('a' + a[i] - 1);
        }
        cout << '\n';
    } else {
        string s;
        cin >> s;
        vector<int> res;
        for(char c: s) {
            res.push_back(c - 'a' + 1);
        }
        cout << res.size() << '\n';
        for(int i: res) cout << i << " ";
        cout << '\n';
    }
}