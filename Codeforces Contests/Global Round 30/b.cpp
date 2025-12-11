//
// b.cpp
// Created by Wasif on 11/06/25 at 19:39:26.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

void solve(){ 
    int n;
    cin >> n;
    vector<int> a(n);
    vector<vector<int>> ind(2);
    map<int, int> pos;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        ind[a[i] & 1].push_back(i);
        pos[a[i]] = ind[a[i] & 1].size() - 1;
    }
    if(ind[0].size() >= 2) {
        int c = 0;
        for(int i = 0; i < n; i++) {
            if(a[i] % 2 == 0) {
                cout << a[i] << " ";
                c++;
            }
            if(c == 2) break;
        }
        cout << '\n';
        return;
    } 
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[j] % a[i] % 2 == 0) {
                cout << a[i] << " " << a[j] << '\n';
                return;
            }
        }
    }
    cout << -1 << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}