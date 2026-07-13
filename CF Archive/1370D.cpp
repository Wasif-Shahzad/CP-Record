//
// 1370D.cpp
// Created by wasifshahzad on 06/22/26 at 12:09:41.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

void solve() {
    // maybe we check if we can make a[i] as our answer
    // for it to happen, we want it to be max from our parity 
    // if we put at odd then we need (k + 1) / 2 elems >= us
    // if we put at even index we need k / 2 elems >= us
    // ideally we want an ascending order type of thing like if even = [x, y, z], odd = [a, b, c]
    // then max(x, y, z) <= min(a, b, c) or vice versa
    // if k = 2, its second min
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int &i: a) cin >> i;
    auto f = [&] (int x) -> bool {
        int cnt = 0, f = 0;
        for(int i = 0; i < n; i++) {
            if(f) {
                cnt++;
                f ^= 1;
            } else if (a[i] <= x) {
                cnt++;
                f ^= 1;
            }
        }
        if(cnt >= k) return true;
        cnt = 0, f = 1;
        for(int i = 0; i < n; i++) {
            if(f) {
                cnt++;
                f ^= 1;
            } else if (a[i] <= x) {
                cnt++;
                f ^= 1;
            }
        }
        return cnt >= k;
    };
    int lo = 0, hi = *max_element(all(a));
    while(hi > lo + 1) {
        int mid = (hi + lo) / 2;
        if(f(mid)) hi = mid;
        else lo = mid;
    }
    cout << hi << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}