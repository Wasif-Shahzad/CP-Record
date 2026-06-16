//
// 1527B2.cpp
// Created by wasifshahzad on 03/26/26 at 19:24:03.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

/*
reverse = forcing opponent
if we're forced, we try to make it a palindrome
we try to make it such a palindrome such that opponent can't make it a palindrome? (unless forced)
reversing doesn't change our correspondance
initial matches stay persistent i.e. a[i] = a[n - i - 1] so these pairs swap
(0, 0) => avoid (unless forced)
(1, 0) or (0, 1) => do it only if we're forced to make a move
if we're not forced just reverse, else find (0, 1). if not then do middle 0 if it exists else (0, 0) 

1100001
1000011
1100011 => B
1101011 => A
1111011 => B
1101111 => reverse by alice
1111111 => B
*/

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int a = 0, b = 0;
    int sm = 0, df = 0, mid = 0;
    for(int i = 0; i < n - i - 1; i++) {
        if(s[i] == s[n - i - 1]) {
            if(s[i] == '0') sm++;
        } else {
            df++;
        }
    }
    if(n & 1) {
        if(s[n / 2] == '0') mid = 1;
    }
    bool turn = true, lst = false;
    while(sm + df + mid > 0) {
        // cout << sm << " " << df << " " << mid << '\n';
        // palindrome if df = 0
        if(df == 1 && mid == 0 && sm > 0) {
            if(turn) a++;
            else b++;
            df--;
            turn = !turn;
            lst = false;
            continue;
        }
        if(df > 0 && !lst) {
            lst = true;
            turn = !turn;
            continue;
        }
        if(turn) a++;
        else b++;
        if(df > 0) df--;
        else if(mid > 0) mid--;
        else sm--, df++;
        turn = !turn;
        lst = false;
    }
    if(a < b) cout << "ALICE\n";
    else if(a == b) cout << "DRAW\n";
    else cout << "BOB\n";
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