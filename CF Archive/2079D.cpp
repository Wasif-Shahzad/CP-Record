//
// 2079D.cpp
// Created by Wasif on 12/10/25 at 23:42:06.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if(k == 1) {
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, a[i] + i + 1);
        }
        cout << ans << '\n';
        return 0;
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    int sum = 0, ans = 0;
    for(int i = 0; i < k - 1; i++) {
        pq.push(a[i]);
        sum += a[i];
    }
    for(int i = k - 1; i < n; i++) {
        int our = (i + 1) - (k - 1);
        ans = max(ans, sum + (k - 1) + a[i] + our);
        if(a[i] < pq.top()) continue;
        int v = pq.top();
        pq.pop();
        sum -= v;
        pq.push(a[i]);
        sum += a[i];
    }
    cout << ans << '\n';
}