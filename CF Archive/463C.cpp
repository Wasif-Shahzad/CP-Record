//
// 463C.cpp
// Created by Wasif on 11/28/25 at 15:49:35.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

/*
row difference or column difference must be odd optimally
we can fix rows and then pre compute the answer for columns. max of both rows will be ours
we can fix columns and then pre compute answer for rows. max of both will be ours
*/

int ur[2001][2001], ul[2001][2001], dr[2001][2001], dl[2001][2001];
int tot[2001][2001];
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    for(int i = 0; i < n; i++) {
        ul[0][i] = ur[0][i] = a[0][i];
        dl[n - 1][i] = dr[n - 1][i] = a[n - 1][i];
    }
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < n; j++) {
            ur[i][j] = ul[i][j] = a[i][j];
            if(j - 1 >= 0) ul[i][j] += ul[i - 1][j - 1];
            if(j + 1 < n) ur[i][j] += ur[i - 1][j + 1];
        }
    }

    for(int i = n - 2; i >= 0; i--) {
        for(int j = 0; j < n; j++) {
            dr[i][j] = dl[i][j] = a[i][j];
            if(j - 1 >= 0) dl[i][j] += dl[i + 1][j - 1];
            if(j + 1 < n) dr[i][j] += dr[i + 1][j + 1];
        }
    }

    vector<int> bstC(n), bstR(n);
    for(int i = 0; i < n; i++) {
        int mx = 0, k = -1;
        for(int j = 0; j < n; j++) {
            tot[i][j] = ul[i][j] + ur[i][j] + dl[i][j] + dr[i][j] - 3 * a[i][j];
            if(tot[i][j] > mx) {
                mx = tot[i][j];
                k = j;
            }
        }
        bstC[i] = k;
    }

    for(int j = 0; j < n; j++) {
        int mx = 0, k = -1;
        for(int i = 0; i < n; i++) {
            if(tot[i][j] > mx) {
                mx = tot[i][j];
                k = i;
            }
        }
        bstR[j] = k;
    }

    int ans = 0;
    int x1, y1, x2, y2;
    x1 = y1 = x2 = y2 = -1;
    int mx1 = -1, mx2 = -1;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if((i + j) & 1) {
                if(tot[i][j] > mx1) {
                    mx1 = tot[i][j];
                    x1 = i, y1 = j;
                }
            } else {
                if(tot[i][j] > mx2) {
                    mx2 = tot[i][j];
                    x2 = i, y2 = j;
                }
            }
        }
    }

    ans = mx1 + mx2;
    cout << ans << '\n';
    cout << x1 + 1 << " " << y1 + 1 << " " << x2 + 1 << " " << y2 + 1 << '\n';
}