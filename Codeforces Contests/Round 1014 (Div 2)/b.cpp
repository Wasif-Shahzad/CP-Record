//
// b.cpp
// Created by wasifshahzad on 01/01/26 at 18:49:58.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        string a, b;
        cin >> a >> b;
        array<int, 2> cnt[2]{};
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                cnt[i & 1][a[i] - '0']++;
                cnt[1 ^ (i & 1)][b[i] - '0']++;
            } else {
                cnt[i & 1][a[i] - '0']++;
                cnt[1 ^ (i & 1)][b[i] - '0']++;
            }
        }
        if(cnt[0][0] >= (n + 1) / 2 && cnt[1][0] >= n / 2) cout << "Yes\n";
        else cout << "No\n";
    }
}