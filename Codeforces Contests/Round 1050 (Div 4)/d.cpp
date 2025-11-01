//
// c.cpp
// Created by Wasif on 09/13/25 at 20:50:29.
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
        int n, k;
        cin >> n >> k;
        vector<int> freq(n + 1, 0), target(n + 1, 0);
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            freq[a[i]]++;
        }
        bool bad = false;

        for(int i = 1; i <= n; i++) {
            if(freq[i] % k) {
                bad = true;
                break;
            }
            target[i] = freq[i] / k;
        }
        if(bad) {
            cout << 0 << '\n';
            continue;
        }
        vector<int> cur(n + 1, 0);
        vector<deque<int>> ind(n + 1);
        int l = -1, ans = 0;
        for(int r = 0; r < n; r++) {
            cur[a[r]]++;
            if(cur[a[r]] > target[a[r]]) {
                l = max(l, ind[a[r]][0]);
                ind[a[r]].pop_front();
                cur[a[r]]--;
            }
            ans += r - l;
            ind[a[r]].push_back(r);
        }
        cout << ans << '\n';
    }
}