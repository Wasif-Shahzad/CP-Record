//
// d.cpp
// Created by wasifshahzad on 12/23/25 at 19:33:27.
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
        set<int> has;
        vector<int> a;
        for(int i = 0; i < (1 << n); i++) has.insert(i);
        for(int i = n; i > 0; i--) {
            a.push_back((1 << i) - 1);
            has.erase(a.back());
            int our = a.back();
            for(int j = our + 1; j < (1 << n); j++) {
                if(!has.count(j)) continue;
                if((j & our) == our) {
                    a.push_back(j);
                    has.erase(j);
                }
            }
        }
        for(int i = 0; i < (1 << n); i += 2) a.push_back(i);
        for(int i: a) cout << i << " ";
        cout << '\n';
    }
}