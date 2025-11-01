//
// b.cpp
// Created by Wasif on 09/20/25 at 19:21:47.
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
        vector<int> ans(2 * n, -1);
        if(n & 1) {
            for(int i = n, j = 0; i > 1; i -= 2, j++) {
                ans[j] = ans[j + i] = i;
            }
            deque<int> d;
            for(int i = n - 1; i > 1; i--) {
                if(i != 1 && (i & 1)) continue;
                d.push_front(i);
            }
            for(int i = n / 2; i < 2 * n; i++) {
                if(ans[i] != -1) continue;
                if(!d.size()) break;
                int our = d.back();
                ans[i] = our;
                int j = i + our;
                while(j < 2 * n && ans[j] != -1) {
                    j += our;
                }
                ans[j] = our;
                d.pop_back();
            }
        } else {
            for(int i = n, j = 0; i > 1; i -= 2, j++) {
                ans[j] = ans[j + i] = i;
            }
            deque<int> d;
            for(int i = 3; i < n; i++) {
                if(i & 1) {
                    d.push_back(i);
                }
            }
            for(int i = n / 2; i < 2 * n; i++) {
                if(ans[i] != -1) continue;
                if(!d.size()) break;
                int our = d.back();
                ans[i] = our;
                int j = i + our;
                while(j < 2 * n && ans[j] != -1) j += our;
                ans[j] = our;
                d.pop_back();
            }
        }
        for(int i = 0; i < 2 * n; i++) if(ans[i] == -1) ans[i] = 1;
        for(int i = 0; i < 2 * n; i++) cout << ans[i] << " ";
        cout << '\n';
    }
}