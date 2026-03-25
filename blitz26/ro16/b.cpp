//
// b.cpp
// Created by wasifshahzad on 03/15/26 at 15:18:22.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

void solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> freq(26, 0);
    for(auto x: s) freq[x - 'a']++;
    int lim = n / k;
    int j = lim - 1;
    string ans;
    while(j >= 0 && k > 0) {
        int x = -1;
        for(int i = 0; i <= j; i++) {
            if(freq[i] == 0) {
                x = i;
                break;
            }
        }
        if(x != -1) {
            ans += char('a' + x);
            j = x - 1;
            for(int i = 0; i <= j; i++) freq[i]--;
            k--;
        } else {
            for(int i = 0; i <= j; i++) {
                if(freq[i] == 1) {
                    x = i;
                    break;
                }
            }
            ans += char('a' + j + 1);
            if(x != -1) {
                j = x - 1;
                for(int i = 0; i <= j; i++) freq[i]--;
                k--;
            } else {
                for(int i = 0; i <= j; i++) freq[i]--;
                k--;
            }
        }
    }
    if(k > 0) {
        for(int i = 0; i < k; i++) ans += 'a';
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