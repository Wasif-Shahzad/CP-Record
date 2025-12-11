//
// b.cpp
// Created by Wasif on 11/03/25 at 20:08:59.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

void first() {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        p[x] = i;
    }
    cout << (p[1] < p[n]) << endl;
}

int ask(int l, int r) {
    assert(l <= r);
    cout << "? " << l << " " << r << endl;
    int x;
    cin >> x;
    return x;
}

void second() {
    int n, x;
    cin >> n >> x;
    pair<int, int> bnd;
    int l = 1, r = n + 1;
    while(r > l + 1) {
        int mid = (l + r) / 2;
        int val = ask(1, mid);
        if(val == n - 1) r = mid;
        else l = mid;
    }
    bnd.second = r;
    l = 0, r = bnd.second;
    while(r > l + 1) {
        int mid = (l + r) / 2;
        int val = ask(mid, n);
        if(val == n - 1)  l = mid;
        else r = mid;
    }
    bnd.first = l;
    if(x) {
        cout << "! " << bnd.second << endl;
    } else {
        cout << "! " << bnd.first << endl;
    }
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    string run;
    cin >> run;
    int t;
    cin >> t;
    while(t--) {
        if(run == "first") first();
        else second();
    }
}