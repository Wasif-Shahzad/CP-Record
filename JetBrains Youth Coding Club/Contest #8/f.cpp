//
// f.cpp
// Created by Wasif on 12/02/25 at 10:12:32.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> time(n);
    for(int i = 0; i < n; i++) {
        string s; cin >> s;
        string f = s.substr(0, 2);
        string t = s.substr(3, 2);
        time[i] = stoi(f) * 60 + stoi(t);
    }
    if(n == 1) {
        cout << "23:59\n";
        return 0;
    }
    sort(time.begin(), time.end());
    int ans = 0;
    for(int i = 1; i < n; i++) {
        ans = max(ans, time[i] - time[i - 1] - 1);
    }
    ans = max(ans, 1439 - time[n - 1] + time[0]);
    int hr = ans / 60, mn = ans % 60;
    printf("%02d:%02d\n", hr, mn);
}