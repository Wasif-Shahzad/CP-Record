//
// h.cpp
// Created by wasifshahzad on 12/22/25 at 18:05:31.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;
const int N = 1e6+1;
int spf[N];

vector<pair<int, int>> get(int x) {
    vector<pair<int, int>> res;
    while(x != 1) {
        pair<int, int> cur = {spf[x], 0};
        int tmp = spf[x];
        while(x % tmp == 0) {
            x /= tmp;
            cur.second++;
        }
        res.push_back(cur);
    }
    return res;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    iota(spf, spf + N, 0);
    for(int i = 2; i < N; i++) {
        if(spf[i] == i) {
            for(int j = i * i; j < N; j += i) {
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
    int T;
    cin >> T;
    while(T--) {
        int n, a, b;
        cin >> n >> a >> b;
        vector<int> A(n);
        for(int i = 0; i < n; i++) {
            cin >> A[i];
        }
        deque<pair<int, int>> sum;
        for(int i = 0; i < n; i++) {
            auto pf = get(A[i]);
            pair<int, int> cur = {0, 0};
            for(auto [v, c]: pf) {
                if(v % 2 == 0) cur.first += v * c;
                else cur.second += v * c;
            }
            if(cur.second == 0) {
                if(a > 0) {
                    a--;
                } else {
                    sum.push_back(cur);
                }
            } else if(cur.first == 0) {
                if(b > 0) {
                    b--;
                } else {
                    sum.push_back(cur);
                }
            } else {
                sum.push_back(cur);
            }
        }
        sort(sum.begin(), sum.end());
        int ans = 0;
        n = sum.size();
        for(int i = 0; i < n; i++) {
            if(n - i == a) {
                ans += sum[i].second;
                a--;
            }
            else if(n - i == b) {
                ans += sum[i].first;
                b--;
            } else {
                if(sum[i].first < sum[i].second) {
                    b--;
                } else {
                    a--;
                }
                ans += min(sum[i].first, sum[i].second);
            }
        }
        cout << ans << '\n';
    }
}