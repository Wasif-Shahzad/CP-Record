//
// g.cpp
// Created by wasifshahzad on 12/18/25 at 12:12:21.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

int mod(string a, int m) {
    reverse(a.begin(), a.end());
    int v = 1, res = 0;
    for(int i = 0; i < (int)a.size(); i++) {
        int here = (a[i] - '0') * v % m;
        res = (res + here) % m;
        v = (v * 10) % m;
    }
    return res;
}

int phi(int n) {
    int ans = n;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) {
            ans -= ans / i;
            while(n % i == 0) n /= i;
        }
    }
    if(n > 1) ans -= ans / n;
    return ans;
}

int power(int a, int b, int m) {
    int ans = 1;
    while(b > 0) {
        if(b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

int calc(string a, string b, int c) {
    int a_new = mod(a, c);
    int p = phi(c);
    bool sm = false;
    if(b.size() <= 10) {
        int B = stoll(b);
        if(B < p) sm = true;
    }
    int b_new = (sm ? stoll(b) : p + mod(b, phi(c)));
    return power(a_new, b_new, c);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string a, b;
    int c;
    cin >> a >> b >> c;
    int up = calc(a, b, c);
    for(int i = b.size() - 1; i >= 0; i--) {
        if(b[i] != '0') {
            int cur = b[i] - '0';
            cur--;
            b[i] = char(cur + '0');
            break;
        }
        b[i] = '9';
    }
    int low = calc(a, b, c);
    int ans = ((up - low) % c + c) % c;
    if(ans == 0) ans = c;
    cout << ans << '\n';
}