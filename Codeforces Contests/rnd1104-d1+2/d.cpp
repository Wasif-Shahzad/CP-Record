//
// d.cpp
// Created by wasifshahzad on 06/18/26 at 20:07:56.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

/*
y
xx
yyx xyy
xxyx yxxx yyyy yyyy xxxy xyxx (just reverse)
yyxyx xyyyx xxxxx xxyyy xxxxx yyyxx yxyyx yxxyy
we either get a +3 in total diff or -3
our sum is 3x-1 or 3x+1. if we end at 1, then our total sum is 3x+1, otherwise 3x-1
it will end kisi aik kone pe to we can iterate over l or r
what else to check other than sum or the sum suffices
sum doesn't suffice otherwise 010 also has -1
more conditions
even if there's one couple then does the suffice with sum?

011110
11 11 11
011 110
0111 1110 1111
*/

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    map<int, int> f;
    vector<int> pref(n + 1, 0);
    for(int i = 1; i <= n; i++) {
        pref[i] += pref[i - 1];
        (s[i - 1] == '1' ? pref[i]++ : pref[i]--);
    }
    for(int i = 1; i <= n; i++) {
        pref[i] %= 3;
        pref[i] = (pref[i] + 3) % 3;
    }
    int r = n, ans = n;
    for(int i = n - 1; i > 0; i--) {
        if(s[i - 1] == s[i]) {
            while(r > i) {
                f[pref[r--]]++;
            }
        }
        int here = f[(pref[i - 1] + 1) % 3] + f[(((pref[i - 1] - 1) % 3) + 3) % 3];
        ans += here;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}