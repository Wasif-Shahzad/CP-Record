//
// 2149D.cpp
// Created by Wasif on 09/26/25 at 08:50:08.
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
        vector<int> a, b;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'a') a.push_back(i);
            else b.push_back(i);
        }
        int a1 = 0, a2 = 0;
        int target;
        int cur = 0;
        if(a.size() > 0) {
            target = a[a.size() / 2] - 1;
            for(int i = a.size() / 2 - 1; i >= 0; i--, target--) {
                cur += target - a[i];
            }
            target = a[a.size() / 2] + 1;
            for(int i = a.size() / 2 + 1; i < a.size(); i++, target++) {
                cur += a[i] - target;
            }
            a1 = cur;
        }
        if(b.size() > 0) {
            target = b[b.size() / 2] - 1;
            cur = 0;
            for(int i = b.size() / 2 - 1; i >= 0; i--, target--) {
                cur += target - b[i];
            }
            target = b[b.size() / 2] + 1;
            for(int i = b.size() / 2 + 1; i < b.size(); i++, target++) {
                cur += b[i] - target;
            }
            a2 = cur;
        }
        cout << min(a1, a2) << '\n';
    }
}