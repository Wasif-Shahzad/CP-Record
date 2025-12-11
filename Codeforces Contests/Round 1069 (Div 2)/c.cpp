//
// c.cpp
// Created by Wasif on 12/06/25 at 13:11:00.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        string s, t;
        cin >> s >> t;
        map<char, int> f1, f2;
        for(auto c: s) f1[c]++;
        for(auto c: t) f2[c]++;
        bool bad = false;
        for(auto [c, cnt]: f1) {
            if(f2[c] < cnt) {
                bad = true;
                break;
            } else {
                f2[c] -= cnt;
            }
        }   
        if(bad) {
            cout << "Impossible\n";
            continue;
        }
        char cur = 'a';
        string ans;
        for(auto c: s) {
            while(cur < c) {
                for(int i = 0; i < f2[cur]; i++) {
                    ans += cur;
                }
                cur++;
            }
            ans += c;
        }
        while(cur <= 'z') {
            for(int i = 0; i < f2[cur]; i++) ans += cur;
            cur++;
        }
        cout << ans << '\n';
    }
}