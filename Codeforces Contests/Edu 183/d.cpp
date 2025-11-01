//
// d.cpp
// Created by Wasif on 10/06/25 at 19:16:46.
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
        // dp[i][j] => block lengths sum upto i, their subarrays sum upto j
        int m = n * (n - 1) / 2, target = m - k;
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        auto f = [&] (int i, int j, auto&& self) -> bool{
            if(j == target) {
                return dp[i][j] = 1;
            }
            if(i > n) return dp[i][j] = 0;
            if(j > m) return dp[i][j] = 0;
            if(dp[i][j] != -1) return dp[i][j];
            int ans = 0;
            for(int len = 2; len <= n - i; len++) {
                int our = len * (len - 1) / 2;
                if(self(i + len, j + our, self)) {
                    ans = 1;
                    break;
                }
            }
            return dp[i][j] = ans;
        };
        bool flag = f(0, 0, f);
        if(flag) {
            int rem = n;
            vector<int> blocks;
            while(rem > 0 && target > 0) {
                bool done = false;
                for(int len = 2; len <= rem; len++) {
                    // current block of of length len
                    int here = len * (len - 1) / 2;
                    if(target >= here && dp[rem][target] == 1 && dp[rem - len][target - here] == 1) {
                        blocks.push_back(len);
                        rem -= len;
                        target -= here;
                        done = true;
                        break;
                    }
                }
                if(!done) {
                    rem--;
                }
            }
            vector<int> ans, cur;
            int j = n;
            for(int b: blocks) {
                cur = {};
                for(int i = 1; i <= b; i++) {
                    cur.push_back(j--);
                }
                reverse(cur.begin(), cur.end());
                for(int i: cur) {
                    ans.push_back(i);
                }
            }
            while(j > 0) {
                ans.push_back(j);
                j--;
            }
            for(int i: ans) cout << i << " ";
            cout << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
}