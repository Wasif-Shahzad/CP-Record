//
// code2.cpp
// Created by Wasif on 11/08/25 at 12:46:12.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    map<int, int> p1, p2;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    string s;
    cin >> s;
    vector<int> pos, neg;
    for(int i = 0; i < n; i++) {
        if(s[i] == '+') {
            pos.push_back(a[i]);
            p1[a[i]]++;
        }
        else {
            neg.push_back(a[i]);
            p2[a[i]]++;
        }
    }
    int ans = 0;
    for(int i: pos) {
        int r = upper_bound(neg.begin(), neg.end(), i + d) - neg.begin();
        int l = lower_bound(neg.begin(), neg.end(), i - d) - neg.begin();
        ans += r - l;
        ans -= p2[i];
    }
    cout << ans << '\n';
}