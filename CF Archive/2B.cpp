//
// 2B.cpp
// Created by wasifshahzad on 8/21/25 at 07:08:12.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

/*
 * zeroes add up
 * f(x) => zeroes in x
 * f(x * y) = f(x) + f(y) ?
 * cnt of pairs of 2's and 5's
 * how to decide b/w ties? :sob:
 *
 */

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    vector<vector<array<int, 2>>> prs(n, vector<array<int, 2>>(n, {0, 0}));
    pair<int, int> zero = {-1, -1};
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            int tmp = a[i][j];
            if (a[i][j] == 0) {
                zero = {i, j};
                continue;
            }
            while (tmp % 2 == 0 && tmp > 0) {
                prs[i][j][0]++;
                tmp /= 2;
            }
            tmp = a[i][j];
            while (tmp % 5 == 0 && tmp > 0) {
                prs[i][j][1]++;
                tmp /= 5;
            }
        }
    }
    vector<vector<array<int, 2>>> dp(n, vector<array<int, 2>>(n, {0, 0}));
    dp[n - 1][n - 1] = prs[n - 1][n - 1];
    for (int i = n - 2; i >= 0; i--) {
        dp[n - 1][i][0] = prs[n - 1][i][0] + dp[n - 1][i + 1][0];
        dp[n - 1][i][1] = prs[n - 1][i][1] + dp[n - 1][i + 1][1];
        dp[i][n - 1][0] = prs[i][n - 1][0] + dp[i + 1][n - 1][0];
        dp[i][n - 1][1] = prs[i][n - 1][1] + dp[i + 1][n - 1][1];
    }
    auto dp2 = dp;
    for (int i = n - 2; i >= 0; i--) {
        for (int j = n - 2; j >= 0; j--) {
            dp[i][j] = min(dp[i + 1][j], dp[i][j + 1]);
            dp[i][j][0] += prs[i][j][0];
            dp[i][j][1] += prs[i][j][1];
            auto tmp1 = dp2[i + 1][j], tmp2 = dp2[i][j + 1];
            swap(tmp1[0], tmp1[1]);
            swap(tmp2[0], tmp2[1]);
            if (tmp1 < tmp2) {
                dp2[i][j] = dp2[i + 1][j];
            } else {
                dp2[i][j] = dp2[i][j + 1];
            }
            dp2[i][j][0] += prs[i][j][0];
            dp2[i][j][1] += prs[i][j][1];
        }
    }
    int first = min(dp[0][0][0], dp[0][0][1]);
    int second = min(dp2[0][0][0], dp2[0][0][1]);
    if (zero.first != -1 && min(first, second) != 0) {
        cout << 1 << '\n';
        for (int i = 0; i < zero.first; i++) {
            cout << "D";
        }
        for (int i = 0; i + 1 < n; i++) {
            cout << "R";
        }
        for (int i = zero.first + 1; i < n; i++) {
            cout << "D";
        }
        cout << '\n';
        return 0;
    }
    string ans;
    int i = 0, j = 0;
    if (first <= second) {
        while (i < n && j < n) {
            const int right = (j + 1 < n ? min(dp[i][j + 1][0], dp[i][j + 1][1]) : (int)1e9);
            if (const int down = (i + 1 < n ? min(dp[i + 1][j][0], dp[i + 1][j][1]) : (int)1e9); down < right) {
                ans += "D";
                i++;
            } else {
                ans += "R";
                j++;
            }
        }
    } else {
        while (i < n && j < n) {
            array<int, 2> right, down;
            right = down = {(int)1e9, (int)1e9};
            if (j + 1 < n) {
                right = dp2[i][j + 1];
            }
            if (i + 1 < n) {
                down = dp2[i + 1][j];
            }
            swap(right[0], right[1]);
            swap(down[0], down[1]);
            if (right <= down) {
                ans += "R";
                j++;
            } else {
                ans += "D";
                i++;
            }
        }
    }
    ans.pop_back();
    cout << min(first, second) << '\n';
    cout << ans << '\n';
}