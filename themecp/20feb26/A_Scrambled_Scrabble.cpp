//
// A_Scrambled_Scrabble.cpp
// Created by wasifshahzad on 02/20/26 at 15:55:29.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

void solve() {
    string s;
    cin >> s;
    vector<int> freq(26, 0);
    vector<int> vov(26, 0);
    vov['a' - 'a'] = vov['e' - 'a'] = vov['i' - 'a'] = vov['o' - 'a'] = vov['u' - 'a'] = 1;
    vov['g' - 'a'] = 4;
    int n = s.size();
    for(int i = 0; i < n; i++) {
        freq[s[i] - 'A']++;
    }
    int ns = freq['n' - 'a'];
    int can = 0;
    for(int i = 0; i < 26; i++) {
        if(vov[i] == 1) can += freq[i], freq[i] = 0;
    }
    int need = 2 * can, h = 0, tn = 0;
    if(ns >= need) {
        h = need;
        freq['n' - 'a'] -= need;
    } else {
        h += freq['n' - 'a'];
        freq['n' - 'a'] -= h;
    }
    for(int i = 0; i < 26; i++) {
        if(vov[i]) continue;
        if(i == 'n' - 'a') continue;
        if(h + freq[i] >= need) {
            freq[i] -= need - h;
            h = need;
            break;
        } else {
            h += freq[i];
            freq[i] = 0;
        }
    }
    tn = ns - freq['n' - 'a'];
    int I = 'g' - 'a';
    int ans = 0;
    if(h == need) {
        ans += can * 3;
        can = need = h = 0;
    } else {
        if(h + freq[I] >= need) {
            freq[I] -= need - h;
            h = need;
            ans += can * 3;
            can = need = h = 0;
        } else {
            // add infront of ns
            int other = h / 2 * 3 + min(tn, freq[I]);
            h += freq[I];
            freq[I] = 0;
            int div = h / 2;
            ans = div * 3;
            cout << max(ans, other) << '\n';
            return;
        }
    }
    if(tn) {   
        ans += min(freq[I], tn);
        freq[I] -= min(freq[I], tn);
    }
    cout << ans << '\n';
    if(freq[24]) {
        int cons = 0;
        for(int i = 0; i < 26; i++) {
            if(vov[i]) continue;
            cons += freq[i];
        }
        ns = freq['n' - 'a'];
        int bst = 0;
        for(int i = 1; i <= freq[24]; i++) {
            need = 2 * i;
            int have = cons - i;
            if(have >= need) {
                bst = max(bst, 3 * i + min({i, ns, freq[I]}));
            } else {
                if(have + freq[I] >= need) {
                    int rem = freq[I] - need + have;
                    int here = 3 * i + min({i, ns, rem});
                    bst = max(bst, here);
                } else {
                    have += freq[I];
                    int c = have / 2;
                    bst = max(bst, 3 * c);
                }
            }
        }
        ans += bst;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}