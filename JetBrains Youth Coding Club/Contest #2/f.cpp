//
// f.cpp
// Created by Wasif on 10/13/25 at 05:13:58.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, m, a;
    cin >> n >> k >> m >> a;
    vector<array<int, 3>> votes(n);
    for(int i = 0; i < n; i++) {
        votes[i][0] = 0;
        votes[i][1] = -1;
        votes[i][2] = i;
    }
    for(int i = 0; i < a; i++) {
        int g;
        cin >> g;
        votes[g - 1][0]++;
        votes[g - 1][1] = i;
    }
    sort(votes.begin(), votes.end(), [](array<int, 3> x, array<int, 3> y) {
        if(x[0] != y[0]) return x[0] > y[0];
        return x[1] < y[1];
    });
    int rem = m - a;
    vector<int> pos(n);
    for(int i = 0; i < n; i++) {
        pos[votes[i][2]] = i;
    }
    for(int i = 0; i < n; i++) {
        int ourp = pos[i];
        if(ourp < k) {
            int ourv = votes[ourp][0];
            int take = k - ourp, need = 0;
            for(int j = ourp + 1; j < n && j <= ourp + take; j++) {
                need += ourv + 1 - votes[j][0];
            }
            if(need > rem) {
                cout << 1 << " ";
                continue;
            }
        }
        auto tmp = votes;
        tmp[ourp][0] += rem;
        tmp[ourp][1] = m - 1;
        sort(tmp.begin(), tmp.end(), [](auto x, auto y) {
            if(x[0] != y[0]) return x[0] > y[0];
            return x[1] < y[1];
        });
        for(int j = 0; j < n; j++) {
            if(tmp[j][2] == i) {
                ourp = j;
            }
        }
        if(ourp < k) cout << 2 << " ";
        else cout << 3 << " ";
    }
    cout << '\n';
}