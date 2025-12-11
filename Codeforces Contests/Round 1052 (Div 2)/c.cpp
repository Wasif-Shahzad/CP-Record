//
// c.cpp
// Created by Wasif on 12/08/25 at 21:04:15.
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
        vector<int> a(n);
        iota(a.begin(), a.end(), 1);
        bool good = true;
        if(s[0] == '0' && s[1] == '1') good = false;
        if(s[n - 1] == '0' && s[n - 2] == '1') good = false;
        for(int i = 1; i + 1 < n; i++) {
            if(s[i] == '0' && s[i - 1] == '1' && s[i + 1] == '1') {
                good = false;
                break;
            }
        }
        if(!good) {
            cout << "No\n";
            continue;
        }
        for(int i = 1; i < n; i++) {
            if(s[i] == '0' && s[i - 1] == '0') swap(a[i], a[i - 1]);
        }
        cout << "Yes\n";
        for(int i = 0; i < n; i++) cout << a[i] << " ";
        cout << '\n';
    }
}