//
// a.cpp
// Created by wasifshahzad on 01/08/26 at 07:10:34.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        int x = 0, y = 0;
        vector<int> a;
        for(int i = 0; i < n; i++) {
            int t; cin >> t;
            if(a.size() && t == a.back()) continue;
            if(t == 1) x++;
            else y++;
            a.push_back(t);
        }
        if(y % 2 == 0) {
            if(y == 0 || (x > 1 && (x & 1))) cout << "Alice\n";
            else cout << "Bob\n"; 
        } else {
            if(x & 1) cout << "Alice\n";
            else cout << "Bob\n";
        }
    }
}