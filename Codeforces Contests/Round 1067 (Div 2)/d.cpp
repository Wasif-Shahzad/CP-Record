//
// d.cpp
// Created by Wasif on 11/30/25 at 12:18:00.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

vector<pair<int, int>> transform(string& s) {
    vector<pair<int, int>> res;
    int n = s.size();
    while(count(s.begin(), s.end(), '1') > 0) {
        int l = 0, r = 2;
        for(int i = 0; i + 1 < n; i++) {
            if(s[i] == s[i + 1]) {
                l = r = i;
                while(r + 1 < n && s[r + 1] == s[l]) r++;
                break;
            }
        }
        for(int i = l; i <= r; i++) {
            s[i] = (s[i] == '1' ? '0' : '1');
        }
        res.push_back({l, r});
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        int n;
        string s, t;
        cin >> n >> s >> t;
        vector<pair<int, int>> op1 = transform(s);
        vector<pair<int, int>> op2 = transform(t);
        cout << op1.size() + op2.size() << '\n';
        reverse(op2.begin(), op2.end());
        for(auto [l, r]: op1) cout << l + 1 << " " << r + 1 << '\n';
        for(auto [l, r]: op2) cout << l + 1 << " " << r + 1 << '\n';
    }
}