//
// 1954D.cpp
// Created by Wasif on 10/20/25 at 20:51:37.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int sumOfMaximumOfSubsets(vector<int> arr, int N)
{
    //    sorting array in decreasing order
    sort(arr.begin(), arr.end());

    //    initializing sum with first element
    int sum = arr[0];
    for (int i = 1; i < N; i++)
    {
        // calculating evaluation similar to horner's rule
        sum = 2 * sum + arr[i];
    }

    return sum;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int mod = 998244353;
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int up = *max_element(a.begin(), a.end());
    vector<vector<int>> dp(n + 1, vector<int>(up + 1, -1));
    auto f = [&] (int i, int mx, auto&& self) -> int{
        if(i == n) {
            return mx;
        }
        if(dp[i][mx] != -1) return dp[i][mx];
        int ans = self(i + 1, max(mx, a[i]), self) % mod;
        ans = (ans + self(i + 1, mx, self)) % mod;
        return dp[i][mx] = ans;
    };
    cout << f(0, 0, f) << '\n';
}