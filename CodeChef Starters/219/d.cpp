//
// d.cpp
// Created by wasifshahzad on 12/31/25 at 19:54:31.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#define all(x) x.begin(), x.end()

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
        string s;
        cin >> s;
        int x = count(all(s), '0');
        int y = count(all(s), '1');
        int mx = min(n, 2 * y);
        int mv = 0;
        vector<int> loc;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') loc.push_back(i);
        }
        for(int i = 0; i < loc.size(); i++) {
            if(loc[i] > 2 * i) {
                mv += loc[i] - 2 * i;
            }
        }
        cout << mx << " " << mv << '\n';
    }
}