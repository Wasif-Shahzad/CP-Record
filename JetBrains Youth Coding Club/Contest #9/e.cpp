//
// e.cpp
// Created by Wasif on 12/09/25 at 07:52:57.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c, d, n;
    cin >> a >> b >> c >> d >> n;
    vector<vector<char>> ans(max(b, d), vector<char>(a + c, '.'));
    auto tmp = ans;
    for(int i = 0; i < min(b, d); i++) {
        for(int j = 0; j < a + c; j++) tmp[i][j] = '#';
    }
    for(int i = min(b, d); i < max(b, d); i++) {
        if(b < d) {
            for(int j = a; j < a + c; j++) tmp[i][j] = '#';
        } else {
            for(int j = 0; j < a; j++) tmp[i][j] = '#';
        }
    }
    deque<pair<int, int>> left, right;
    for(int j = a - 1, x = 0; j >= 0; j--, x ^= 1) {
        if(x == 0) {
            for(int i = 0; i < b; i++) left.push_back({i, j});
        } else {
            for(int i = b - 1; i >= 0; i--) left.push_back({i, j});
        }
    }
    for(int j = a, x = 0; j < a + c; j++, x ^= 1) {
        if(x == 0) {
            for(int i = 0; i < d; i++) right.push_back({i, j});
        } else {
            for(int i = d - 1; i >= 0; i--) right.push_back({i, j});
        }
    }
    if(b > d) {
        reverse(left.begin(), left.end());
    } else {
        reverse(right.begin(), right.end());
        swap(left, right);
    }
    vector<pair<int, int>> x(n);
    for(int i = 0; i < n; i++) {
        cin >> x[i].first;
        x[i].second = i;
    }
    sort(x.rbegin(), x.rend());
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < x[i].first; j++) {
            int pi, pj;
            if(left.size()) {
                pi = left[0].first, pj = left[0].second;
                left.pop_front();
            } else {
                pi = right[0].first, pj = right[0].second;
                right.pop_front();
            }
            ans[pi][pj] = char(x[i].second + 'a'); 
        }
    }
    cout << "YES\n";
    for(int i = 0; i < max(b, d); i++) {
        for(int j = 0; j < a + c; j++) cout << ans[i][j];
        cout << '\n';
    }
}