//
// Created by wasifshahzad on 8/16/25.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    if (s == "red") cout << "SSS";
    else if (s == "blue") cout << "FFF";
    else if (s == "green") cout << "MMM";
    else cout << "Unknown";
}