//
// p3.cpp
// Created by Wasif on 11/30/25 at 15:39:34.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

int ask(vector<int>& a) {
    cout << "? " << a.size() << " ";
    for(int i: a) cout << i << " ";
    cout << endl;
    int x; cin >> x;
    return x;
}

signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);

    int T;
    cin >> T;
    while(T--) {
        int n;
        cin >> n;
        vector<int> ans(2 * n + 1, -1), bad(2 * n + 1, 0);
        vector<int> cur = {1};
        bad[1] = 1;
        for(int i = 2; i <= 2 * n; i++) {
            cur.push_back(i);
            int res = ask(cur);
            if(res != 0) {
                ans[i] = res;
                cur.pop_back();
            } else {
                bad[i] = 1;
            }
        }
        for(int i = 2; i <= 2 * n; i++) {
            if(ans[i] == -1 && !bad[i]) {
                cur.push_back(i);
                ans[i] = ask(cur);
                cur.pop_back();
            }
        }
        bad.assign(2 * n + 1, 0);
        cur.clear();
        for(int i = 1; i <= 2 * n; i++) {
            if(ans[i] != -1) {
                cur.push_back(i);
                bad[i] = 1;
            }
        }

        for(int i = 1; i <= 2 * n; i++) {
            if(ans[i] == -1) {
                cur.push_back(i);
                ans[i] = ask(cur);
                cur.pop_back();
            }
        }

        cout << "! ";
        for(int i = 1; i <= 2 * n; i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}