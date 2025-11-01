//
// e.cpp
// Created by Wasif on 10/28/25 at 21:11:10.
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
        int n, k, x;
        cin >> n >> k >> x;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        vector<int> l(n, -1), r(n, -1);
        auto f = [&] (int x) -> bool{
            if(x == 0) {
                for(int i = 0; i < n; i++) {
                    l[i] = r[i] = a[i];
                }
                return true;
            }
            l.assign(n, -1);
            r.assign(n, -1);
            for(int i = 0; i < n; i++) {
                l[i] = a[i] - k;
                r[i] = a[i] + k;
            }
            int cnt = 0;
            if(l[0] >= 0) cnt += l[0] + 1;
            for(int i = 1; i < n; i++) {
                if(l[i] >= r[i - 1]) cnt += l[i] - r[i - 1] + 1;
            }
            if(r[n - 1] != x) cnt += x - r[n - 1] + 1;
            return cnt >= k;
        };
        int lo = -1, hi = 1;
        while(f(hi)) hi *= 2;
        while(hi > lo + 1) {
            int mid = (hi + lo) / 2;
            if(f(mid)) lo = mid;
            else hi = mid;
        }
        vector<int> ans;
        if(l[0] >= 0) {
            for(int i = 0; i <= l[0] && k > 0; i++, k--) {
                ans.push_back(i);
            }
        }
        if(r[n - 1] <= x) {
            for(int i = r[n - 1]; i <= x && k > 0; i++, k--) {
                ans.push_back(i);
            }
        }
        for(int i = 1; i < n; i++) {
            if(r[i - 1] <= l[i]) {
                for(int j = r[i - 1]; j <= l[i] && k > 0; j++, k--) {
                    ans.push_back(j);
                }
            }
        }
        for(int i: ans) cout << i << " ";
        cout << '\n';
    }
}