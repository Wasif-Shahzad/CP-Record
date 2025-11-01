//
// c.cpp
// Created by Wasif on 10/06/25 at 19:16:48.
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
        string s;
        cin >> s;
        int x = count(s.begin(), s.end(), 'a'), y = count(s.begin(), s.end(), 'b');
        int need = x - y;
        if(need == 0) {
            cout << 0 << '\n';
            continue;
        }
        map<int, int> has;
        has[0] = -1;
        int cur = 0;
        int ans = n;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'a') cur++;
            else cur--;
            int our = cur - need;
            if(has.count(our)) {
                ans = min(ans, i - has[our]);
            }
            has[cur] = i;
        }
        cout << (ans == n ? -1 : ans) << '\n';
    }
}