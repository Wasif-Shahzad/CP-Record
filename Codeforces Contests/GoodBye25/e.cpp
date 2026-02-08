//
// e.cpp
// Created by wasifshahzad on 12/27/25 at 22:13:45.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

int ask(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int x; cin >> x;
    if(x == -1) exit(0);
    return x;
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        int l = 1, r = n + 1;
        while(r > l + 1) {
            int mid = (l + r) / 2;
            int a = ask(max(1ll, l), mid - 1);
            int b = ask(mid, min(n, r));
            if(a > b) r = mid;
            else l = mid;
        }
        int res = ask(l, l);
        cout << "! " << res << endl;
    }
}