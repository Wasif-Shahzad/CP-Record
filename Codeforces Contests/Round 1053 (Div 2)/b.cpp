//
// b.cpp
// Created by Wasif on 09/24/25 at 16:29:30.
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
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        set<int> st;
        for(int i = 0; i < m; i++) {
            int x; cin >> x;
            st.insert(x);
        }
        int cur = 1;
        for(int i = 0; i < n; i++) {
            if(s[i] == 'A') {
                cur++;
                st.insert(cur);
            } else {
                cur++;
                while(st.count(cur)) cur++;
                st.insert(cur);
                cur++;
                while(st.count(cur)) cur++;
            }
        }
        cout << st.size() << '\n';
        for(int i: st) cout << i << " ";
        cout << '\n';
    }
}