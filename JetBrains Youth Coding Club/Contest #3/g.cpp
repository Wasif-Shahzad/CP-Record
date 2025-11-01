//
// g.cpp
// Created by Wasif on 10/19/25 at 11:19:59.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, a, b, c;
    cin >> n >> m >> a >> b >> c;
    if(n % 2 == 1 && m % 2 == 1) {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }
    vector<vector<char>> ans(n, vector<char>(m));
    if(n % 2 == 1) {
        if(a < m / 2) {
            cout << "IMPOSSIBLE" << '\n';
            return 0;
        }
        for(int i = 0, j = 0; i < m; i += 2, j ^= 1) {
            if(j) ans[n - 1][i] = ans[n - 1][i + 1] = 'x';
            else ans[n - 1][i] = ans[n - 1][i + 1] = 'y';
        }
        n--;
        a -= m / 2;
    } else if(m % 2 == 1) {
        if(b < n / 2) {
            cout << "IMPOSSIBLE" << '\n';
            return 0;
        }
        for(int i = 0, j = 0; i < n; i += 2, j ^= 1) {
            if(j) ans[i][m - 1] = ans[i + 1][m - 1] = 'x';
            else ans[i][m - 1] = ans[i + 1][m - 1] = 'y';
        }
        m--;
        b -= n / 2;
    }
    int need = n / 2 * m / 2;
    int have = c + a / 2 + b / 2;
    if(have < need) {
        cout << "IMPOSSIBLE" << '\n';
        return 0;
    }
    for(int i = 0; i < n; i += 2) {
        for(int j = 0; j < m; j += 2) {
            set<char> have;
            if(i) {
                have.insert(ans[i - 1][j]);
                have.insert(ans[i - 1][j + 1]);
            }
            if(j) {
                have.insert(ans[i][j - 1]);
                have.insert(ans[i + 1][j - 1]);
            }
            char our1 = 'a', our2 = 'a';
            while(have.count(our1)) our1++;
            have.insert(our1);
            while(have.count(our2)) our2++;
            if(c > 0) {
                ans[i][j] = ans[i][j + 1] = ans[i + 1][j] = ans[i + 1][j + 1] = our1;
                c--;
            } else if(b > 1) {
                ans[i][j] = ans[i + 1][j] = our1;
                ans[i][j + 1] = ans[i + 1][j + 1] = our2;
                b -= 2;
            } else if(a > 1) {
                ans[i][j] = ans[i][j + 1] = our1;
                ans[i + 1][j] = ans[i + 1][j + 1] = our2;
                a -= 2;
            } else {
                cout << "IMPOSSIBLE\n";
                return 0;
            }
        }
    }
    for(auto row: ans) {
        for(auto ch: row) cout << ch;
        cout << '\n';
    }
}