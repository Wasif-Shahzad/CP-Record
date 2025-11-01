//
// g.cpp
// Created by Wasif on 10/09/25 at 20:17:54.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if(a[n - 1] != 0) {
        cout << "NO\n";
        return 0;
    }
    if(n == 1) {
        cout << "YES\n0\n";
        return 0;
    }
    int suff_zeros = 1, j = n - 2;
    while(j >= 0 && a[j] == 0) {
        suff_zeros++;
        j--;
    }
    if(suff_zeros >= 3) {
        cout << "YES\n";
        for(int i = 0; i < n; i++) {
            if(i == n - 3) cout << "(";
            cout << a[i];
            if(i == n - 2) cout << ")";
            if(i + 1 < n) cout << "->";
        }
        cout << '\n';
    } else if(suff_zeros == 1) {
        cout << "YES\n";
        for(int i = 0; i < n; i++) {
            cout << a[i];
            if(i + 1 < n) cout << "->";
        }
        cout << '\n';
    } else {
        while(j >= 0 && a[j] == 1) j--;
        if(j < 0) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
            for(int i = 0; i < n; i++) {
                if(i == j) cout << "(";
                if(i == j + 1) cout << "((";
                cout << a[i];
                if(i == n - 3) cout << ")";
                if(i == n - 2) cout << "))";
                if(i + 1 < n) cout << "->";
            }
            cout << '\n';
        }
    }
}