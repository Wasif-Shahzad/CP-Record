//
// c.cpp
// Created by Wasif on 12/11/25 at 19:31:15.
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
        vector<int> a(n);
        priority_queue<int> odd, even;
        vector<int> tmp, tmp2;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(a[i] & 1) {
                odd.push(a[i]);
                tmp.push_back(a[i]);
            } else {
                even.push(a[i]);
                tmp2.push_back(a[i]);
            }
        }
        if(odd.empty()) {
            for(int i = 0; i < n; i++) {
                cout << 0 << " ";
            }
            cout << '\n';
            continue;
        }
        sort(tmp.begin(), tmp.end());
        sort(tmp2.begin(), tmp2.end());
        int ans = odd.top();
        odd.pop();
        cout << ans << " ";
        int sz = even.size();
        if(sz == 0) {
            for(int i = 1; i < n; i++) {
                cout << (i & 1 ? 0 : ans) << " ";
            }
            cout << '\n';
            continue;
        }
        for(int i = 0; i < sz; i++) {
            ans += even.top();
            even.pop();
            cout << ans << " ";
        }
        int t = ans - tmp2[0];
        if(tmp.size() == 2) cout << 0 << " ";
        else if(tmp.size() >= 3) {
            cout << t << " ";
        }
        for(int i = sz + 2; i < n; i++) {
            int diff = (i + 1) - (sz + 1);
            if(diff % 2 == 0) cout << ans << " ";
            else {
                if(i + 1 < n) cout << t << " ";
                else cout << 0 << " ";
            }
        }
        cout << '\n';
    }
}