//
// 2149C.cpp
// Created by Wasif on 09/26/25 at 08:34:05.
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
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        vector<int> freq(n + 1, 0);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            freq[a[i]]++;
        }
        int cnt = 0;
        for(int i = 0; i < k; i++) {
            if(freq[i] == 0) cnt++;
        }
        if(freq[k] >= cnt) cnt = freq[k];
        cout << cnt << '\n';
    }
}