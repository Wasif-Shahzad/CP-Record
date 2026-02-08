//
// e.cpp
// Created by wasifshahzad on 12/23/25 at 19:33:30.
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
        int n, x, y;
        cin >> n >> x >> y;
        string s;
        cin >> s;
        vector<int> p(n);
        bool zero = false, one = false;
        for(int i = 0; i < n; i++) {
            cin >> p[i];
            if(s[i] == '0') zero = true;
            else one = true;
        }  
        int tot = accumulate(p.begin(), p.end(), 0ll);
        if(tot > x + y) {
            cout << "No\n";
            continue;
        }
        int hx = 0, hy = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '0') {
                hx += p[i];
            } else {
                hy += p[i];
            }
        }
        if(hx <= x && hy <= y) {
            if(zero && one) {
                cout << "Yes\n";
                continue;
            }
            int can = 0;
            for(int i = 0; i < n; i++) {
                if(p[i] % 2 == 0) {
                    can += (p[i] - 1) / 2;
                } else {
                    can += p[i] / 2;
                }
            }
            if(zero) {
                cout << (can >= y ? "Yes" : "No") << '\n';
            } else {
                cout << (can >= x ? "Yes" : "No") << '\n';
            }
            continue;
        }
        if(!((hx > x && hy < y) || (hx < x && hy > y))) {
            cout << "No\n";
            continue;
        }
        int need, can = 0;
        if(hx > x) {
            need = y - hy;
            for(int i = 0; i < n; i++) {
                if(s[i] == '0') {
                    if(p[i] % 2 == 0) {
                        can += (p[i] - 1) / 2;
                    } else {
                        can += p[i] / 2;
                    }
                }
            }
        } else {
            need = x - hx;
            for(int i = 0; i < n; i++) {
                if(s[i] == '1') {
                    if(p[i] % 2 == 0) {
                        can += (p[i] - 1) / 2;
                    } else {
                        can += p[i] / 2;
                    }
                }
            }
        }
        if(can >= need) {
            cout << "Yes\n"; 
        } else {
            cout << "No\n";
        }
    }
}