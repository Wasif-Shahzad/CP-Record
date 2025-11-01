//
// c.cpp
// Created by Wasif on 10/04/25 at 06:27:56.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int ans = 0;
    vector<int> nums{2, 3, 4, 5, 6, 7, 8, 9, 10};
    int m = nums.size();
    for(int i = 1; i < (1 << m); i++) {
        int cur = 1;
        for(int j = 0; j < m; j++) {
            if((1 << j) & i) {
                cur = lcm(cur, nums[j]);
            }
        }
        if(__builtin_popcount(i) & 1) ans += n / cur;
        else ans -= n / cur;
    }
    cout << n - ans << '\n';
}