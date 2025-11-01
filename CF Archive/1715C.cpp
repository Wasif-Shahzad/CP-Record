//
// 1715C.cpp
// Created by Wasif on 09/10/25 at 15:53:04.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        int j = i;
        while(j + 1 < n && a[i] == a[j + 1]) j++;
        int in = j - i + 1;
        ans += in * (in + 1) / 2;
        int l = i, r = n - j - 1;
        ans += l * r;
        ans += l * in;
        ans += r * in;
        i = j;
    }
    while(m--) {
        int i, x;
        cin >> i >> x;
        i--;
        if(i) {
            if(a[i] == a[i - 1]) {
                if(x != a[i]) {
                    ans += i;
                }
            } else {
                if(x == a[i - 1]) {
                    ans -= i;
                }
            }
        }
        if(i + 1 < n) {
            if(a[i] == a[i + 1]) {
                if(x != a[i]) {
                    ans += n - i - 1;
                }
            } else {
                if(x == a[i + 1]) {
                    ans -= n - i - 1;
                }
            }
        }
        if(i && i + 1 < n) {
            int l = i, r = n - i - 1;
            if(a[i - 1] == a[i + 1]) {
                if(a[i] == a[i - 1]) {
                    if(x != a[i - 1]) {
                        ans += l * r * 2;
                    }
                } else {
                    if(x == a[i - 1]) {
                        ans -= l * r * 2;
                    }
                }
            } else {
                if(a[i] == a[i - 1] || a[i] == a[i + 1]) {
                    if(x != a[i - 1] && x != a[i + 1]) {
                        ans += l * r;
                    }
                } else {
                    if(x == a[i - 1] || x == a[i + 1]) {
                        ans -= l * r;
                    }
                }
            }
        }
        a[i] = x;
        cout << ans << '\n';
    }
}