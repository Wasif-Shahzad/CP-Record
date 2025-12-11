//
// a.cpp
// Created by Wasif on 11/21/25 at 20:52:12.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string tmp;
    cin >> tmp;
    bool check = (tmp[0] == '*' || tmp.back() == '*');
    string s;
    for(auto i: tmp) {
        if(i != '*') s += i;
    }
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        string t;
        cin >> t;
        if(s.empty()) cout << t << '\n';
        else if(tmp[0] == '*') {
            bool good = true;
            for(int i = s.size() - 1, j = t.size() - 1; i >= 0; i--, j--) {
                if(j >= 0 && s[i] != t[j]) {
                    good = false;
                    break;
                } else if(j < 0) {
                    good = false;
                    break;
                }
            }
            if(good) cout << t << '\n';
        } else if(tmp.back() == '*') {
            bool good = true;
            for(int i = 0, j = 0; i < s.size(); i++, j++) {
                if(j < t.size() && s[i] != t[j]) {
                    good = false;
                    break;
                } else if(j == t.size()) {
                    good = false;
                    break;
                }
            }
            if(good) cout << t << '\n';
        } else {
            int k = 0;
            for(int i = 0; i < tmp.size(); i++) {
                if(tmp[i] == '*') {
                    k = i;
                    break;
                }
            }
            bool good = true;
            for(int i = 0; i < k; i++) {
                if(i == t.size()) {
                    good = false;
                    break;
                }
                if(t[i] != tmp[i]) {
                    good = false;
                    break;
                }
            }
            for(int i = tmp.size() - 1, j = t.size() - 1; i > k; i--, j--) {
                if(j < k) {
                    good = false;
                    break;
                }
                if(tmp[i] != t[j]) {
                    good = false;
                    break;
                }
            }
            if(good) cout << t << '\n';
        }
    }
}