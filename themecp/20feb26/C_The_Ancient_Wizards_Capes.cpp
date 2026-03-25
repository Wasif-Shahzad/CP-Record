//
// C_The_Ancient_Wizards_Capes.cpp
// Created by wasifshahzad on 02/20/26 at 15:39:30.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &i: a) cin >> i;
    if(n == 1) {
        cout << 2 << '\n';
        return;
    }
    auto check = [&] (vector<int> b) -> bool {
        vector<int> cnt(n, 1);
        int cur = 0;
        for(int i = 0; i < n; i++) {
            cnt[i] += cur;
            cur += (b[i] == -1);
        }
        cur = 0;
        for(int i = n - 1; i >= 0; i--) {
            cnt[i] += cur;
            cur += (b[i] == 1);
        }
        return cnt == a;
    }; 
    // +1 => left left
    // -1 => right right
    // 0 => left/right or right/left
    vector<int> comb(n, 0);
    bool need = false;
    for(int i = 1; i < n; i++) {
        if(abs(a[i] - a[i - 1]) > 1) {
            cout << 0 << '\n';
            return;
        }
        if(a[i] > a[i - 1]) comb[i - 1] = comb[i] = -1;
        else if(a[i] < a[i - 1]) comb[i - 1] = comb[i] = 1;
        else {
            if(comb[i - 1] == 0) {
                comb[i - 1] = -1, comb[i] = 1;
                need = true;
            } else {
                comb[i] = (comb[i - 1] == 1 ? -1 : 1);
            }
        }
    }
    int ans = check(comb);
    if(need) {
        comb.assign(n, 0);
        for(int i = 1; i < n; i++) {
            if(a[i] > a[i - 1]) comb[i - 1] = comb[i] = -1;
            else if(a[i] < a[i - 1]) comb[i - 1] = comb[i] = 1;
            else {
                if(comb[i - 1] == 0) {
                    comb[i - 1] = 1, comb[i] = -1;
                    need = true;
                } else {
                    comb[i] = (comb[i - 1] == 1 ? -1 : 1);
                }
            }
        }
        ans += check(comb); 
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}