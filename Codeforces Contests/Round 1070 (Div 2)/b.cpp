//
// b.cpp
// Created by Wasif on 12/11/25 at 19:31:19.
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
        string s;
        cin >> s;
        s += s;
        n += n;
        if(count(s.begin(), s.end(), '0') == 0) {
            cout << 0 << '\n';
            continue;
        }
        int lst = -1;
        int ans = 0;
        for(int i = 0; i + 1 < n; i++) {
            if(s[i] == '0') {
                if(lst == -1) continue;
                ans = max(ans, i - lst);
            } else {
                lst = i;
            }
        }
        cout << ans << '\n';
    }
}