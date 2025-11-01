//
// c.cpp
// Created by Wasif on 09/20/25 at 20:01:51.
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
        vector<array<int, 2>> dp(n, {-1, -1});
        auto f = [&] (int i, bool notFree, auto&& self) -> int{
            if(i == n) {
                if(notFree) {
                    if(s[n - 1] == '0') return 1;
                    else return 0;
                } else return 1;
            }
            if(dp[i][notFree] != -1) return dp[i][notFree];
            if(i > 1 && notFree && s[i - 1] == s[i - 2] && s[i - 1] == '1' && s[i] == '0') return 0;
            int ans = 0;
            if(s[i] == '0') {
                if(i == 0) ans = self(i + 1, false, self);
                else if(i > 1 && s[i - 1] == '1' && s[i - 2] == '0' && notFree) ans = self(i + 1, false, self);
                else if(i > 0 && s[i - 1] == '0') ans = self(i + 1, false, self);
                bool must = (i > 1 && s[i - 1] == '1' && s[i - 2] == '0' && notFree);
                if(!must) ans = max(ans, self(i + 1, true, self));
            } else {
                ans = self(i + 1, notFree, self);
            }
            return dp[i][notFree] = ans;
        };
        cout << (f(0, 0, f) ? "YES" : "NO") << '\n'; 
    }
}