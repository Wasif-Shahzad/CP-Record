//
// 1977C.cpp
// Created by Wasif on 12/11/25 at 12:01:03.
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
        map<int, int> freq;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            freq[a[i]]++;
        }
        sort(a.begin(), a.end());
        a.erase(unique(a.begin(), a.end()), a.end());
        int m = a.size();
        int mx = a[m - 1];
        int l = a[0];
        for(int i = 1; i < m; i++) {
            l = lcm(l, a[i]);
            if(l > mx) {
                break;
            }
        }
        if(l != mx) {
            cout << n << '\n';
            continue;
        }
        auto find = [&] (int d) -> int {
            int curLCM = 0, cnt = 0;
            for(auto [v, c]: freq) {
                if(d % v == 0) {
                    if(curLCM == 0) curLCM = v;
                    else {
                        curLCM = lcm(curLCM, v);
                    }
                    cnt += c;
                }
            }
            if(curLCM != d) cnt = 0;
            return cnt;
        };
        int ans = 0;
        vector<int> facts;
        for(int i = 1; i * i <= mx; i++) {
            if(mx % i == 0) {
                if(!freq.count(i)) {
                    ans = max(ans, find(i));
                }
                if(mx / i != i && !freq.count(mx / i)) {
                    ans = max(ans, find(mx / i));
                }
            }
        }
        cout << ans << '\n';
    }
}