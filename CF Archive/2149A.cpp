//
// 2149A.cpp
// Created by Wasif on 09/26/25 at 08:42:09.
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
        vector<int> a(n);
        int mk = 0, cnt = 0;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            mk += (a[i] == 0);
            cnt += (a[i] == -1);
        }
        mk += (cnt & 1) * 2;
        cout << mk << '\n';
    }
}