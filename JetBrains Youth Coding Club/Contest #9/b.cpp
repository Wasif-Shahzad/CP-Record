//
// b.cpp
// Created by Wasif on 12/09/25 at 07:28:16.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

void increase(string& s) {
    string hr, mn;
    hr += s[0], hr += s[1];
    mn += s[3], mn += s[4];
    int time = stoi(hr) * 60 + stoi(mn);
    time++;
    time %= 1440;
    int nhr = time / 60, nmn = time % 60;
    string ntime = to_string(nhr);
    if(ntime.size() == 1) ntime = '0' + ntime;
    ntime += ":";
    string tbd = to_string(nmn);
    if(tbd.size() == 1) tbd = '0' + tbd;
    ntime += tbd;
    s = ntime;
}

bool isPalindrome(string s) {
    string t = s;
    reverse(t.begin(), t.end());
    return t == s;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int ans = 0;
    while(true) {
        if(isPalindrome(s)) break;
        increase(s);
        ans++;
    }
    cout << ans << '\n';
}