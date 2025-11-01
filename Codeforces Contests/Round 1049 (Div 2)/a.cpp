//
// a.cpp
// Created by Wasif on 09/09/25 at 19:32:35.
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
        int n;
        cin >> n;
        string s;
        cin >> s;
        int cnt = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(s[i] == '0') {
                int have = -1;
                for(int j = i - 1; j >= 0; j--) {
                    if(s[j] == '1') {
                        have = j;
                    }
                }
                if(have == -1) break;
                s[have] = '0';
                s[i] = '1';
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
}