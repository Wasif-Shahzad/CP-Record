//
// b.cpp
// Created by Wasif on 10/24/25 at 19:32:53.
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
        int n, q;
        cin >> n >> q;
        string s;
        cin >> s;
        vector<int> a(q);
        for(int i = 0; i < q; i++) {
            cin >> a[i];
        }
        vector<pair<int, int>> div;
        int cnt = 0;
        for(int i = n - 1; i >= 0 && s[i] == 'A'; i--, cnt++);
        for(int i = 0; i < n && s[i] == 'A'; i++, cnt++);
        int j = -1;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'B') {
                j = i;
                div.push_back({i, cnt});
                break;
            }
        }
        if(j == -1) {
            for(int i = 0; i < q; i++) {
                cout << a[i] << '\n';
            }
            continue;
        }
        cnt = 0;
        for(int i = j + 1; i < n; i++) {
            if(s[i] == 'A') cnt++;
            else {
                div.push_back({i, cnt});
                cnt = 0;
            }
        }
        for(int i = 0; i < q; i++) {
            if(a[i] <= j) {
                cout << a[i] << '\n';
                continue;
            }
            int ans = j + 1;
            a[i] -= j;
            a[i] /= 2;
            if(div.size() == 1) {
                while(a[i] > 0) {
                    if(a[i] <= div[0].second) {
                        ans += a[i];
                        a[i] = 0;
                    } else {
                        ans += div[0].second + 1;
                        a[i] -= div[0].second;
                        a[i] /= 2;
                    }
                }
            } else {
                int j = 1;
                while(a[i] > 0) {
                    if(a[i] <= div[j].second) {
                        ans += a[i];
                        a[i] = 0;
                    } else {
                        ans += div[j].second + 1;
                        a[i] -= div[j].second;
                        a[i] /= 2;
                    }
                    j = (j + 1) % (int)div.size();
                }
            }
            cout << ans << '\n';
        }
    }
}