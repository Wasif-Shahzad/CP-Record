//
// a2.cpp
// Created by Wasif on 11/03/25 at 19:48:02.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

string convertobase25(int x) {
    vector<int> res;
    while(x > 0) {
        res.push_back(x % 25);
        x /= 25;
    }
    reverse(res.begin(), res.end());
    string cur;
    for(int i: res) {
        cur += char('a' + i);
    }
    return cur;
}

int converttoint(string conv) {
    vector<int> res;
    for(char c: conv) {
        res.push_back(c - 'a');
    }
    int ans = 0, p = 1;
    reverse(res.begin(), res.end());
    for(int i: res) {
        ans += p * i;
        p *= 25;
    }
    return ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string run;
    cin >> run;
    if(run == "first" ) {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            string conv = convertobase25(a[i]);
            cout << conv << 'z';
        }
        cout << '\n';
    } else {
        string s;
        cin >> s;
        string cur;
        vector<int> a;
        for(char c: s) {
            if(c == 'z') {
                int num = converttoint(cur);
                a.push_back(num);
                cur = "";
            } else {
                cur += c;
            }
        }
        if(cur.size()) {
            a.push_back(converttoint(cur));
        }
        cout << a.size() << '\n';
        for(int i: a) cout << i << " ";
        cout << '\n';
    }
}