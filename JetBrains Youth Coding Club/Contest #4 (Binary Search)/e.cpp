//
// e.cpp
// Created by Wasif on 10/29/25 at 15:02:35.
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
        int n;
        cin >> n;
        vector<int> p(n + 1, 0);
        for(int i = 1; i <= n; i++) {
            cin >> p[i];
        }
        sort(p.rbegin(), p.rend());
        int x, a, y, b;
        cin >> x >> a >> y >> b;
        int k;
        cin >> k;
        auto f = [&] (int j) -> bool{
            vector<int> marked(n + 1, 0);
            vector<int> order;
            for(int i = 1; i <= j; i++) {
                if(i % a == 0 && i % b == 0) {
                    order.push_back(i);
                    marked[i] = 1;
                }
            }
            for(int i = 1; i <= j; i++) {
                if(x > y) {
                    if(i % a == 0 && i % b) {
                        order.push_back(i);
                        marked[i] = 1;
                    }
                } else {
                    if(i % b == 0 && i % a) {
                        order.push_back(i);
                        marked[i] = 1;
                    }
                }
            }
            for(int i = 1; i <= j; i++) {
                if(x <= y) {
                    if(i % a == 0 && i % b && !marked[i]) {
                        order.push_back(i);
                        marked[i] = 1;
                    }
                } else {
                    if(i % b == 0 && i % a && !marked[i]) {
                        order.push_back(i);
                        marked[i] = 1;
                    }
                }
            }
            int can = 0;
            int pt = 0;
            for(int i: order) {
                if(i % a == 0 && i % b == 0) {
                    can += p[pt] / 100 * (x + y);
                } else if(i % a == 0) {
                    can += p[pt] / 100 * x;
                } else {
                    can += p[pt] / 100 * y;
                }
                pt++;
            }
            return can >= k;
        };
        int lo = 0, hi = n + 1;
        if(!f(n)) {
            cout << -1 << '\n';
            continue;
        }
        while(hi > lo + 1) {
            int mid = (hi + lo) / 2;
            if(f(mid)) hi = mid;
            else lo = mid;
        }
        cout << hi << '\n';
    }
}