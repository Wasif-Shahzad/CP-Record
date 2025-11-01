//
// d.cpp
// Created by Wasif on 10/24/25 at 20:44:55.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int ask(int i, int x) {
    cout << "? " << i << " " << x << endl;
    int v;
    cin >> v;
    return v;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        int ans = 0;
        vector<int> space, ind;
        for(int i = 1; i <= n; i++) {
            space.push_back(i);
            if(i != n) ind.push_back(i);
        }
        for(int p = 1; p <= n; p *= 2) {
            int total = 0;
            for(int i: space) {
                if(i & p) {
                    total++;
                }
            }
            int have = 0;
            vector<int> good, bad;
            for(int i: ind) {
                int here = ask(i, p);
                if(here) {
                    good.push_back(i);
                    have++;
                } else {
                    bad.push_back(i);
                }
            }
            if(have == total) {
                // this bit is off
                vector<int> nspace;
                for(int i: space) {
                    if(i & p) continue;
                    nspace.push_back(i);
                }
                ind = bad;
                space = nspace;
            } else {
                // this bit is on
                ans |= p;
                vector<int> nspace;
                for(int i: space) {
                    if(i & p) {
                        nspace.push_back(i);
                    }
                }
                ind = good;
                space = nspace;
            }
        }
        cout << "! " << ans << endl;
    }
}