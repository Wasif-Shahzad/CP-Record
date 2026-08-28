//
// gen.cpp
// Created by wasifshahzad on 12/23/25 at 20:56:09.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

const int MOD1 = 1e9+7;
const int MOD2 = 998244353;

int generateRandomInt(int l, int r) {
    // UPDATED: Made engine static to prevent re-seeding every call
    // which causes identical values in tight loops.
    static unsigned seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();
    static std::mt19937 eng(seed);

    std::uniform_int_distribution<int> distrib(l, r);
    return distrib(eng);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << 1 << '\n';
    // Macro from your snippet
    #define get(l, r) generateRandomInt(l, r)
    int n = get(1, 50), k = get(1, 20);
    cout << n << " " << k << '\n';
    for(int i = 0; i < n; i++) {
        cout << get(1, 20) << " ";
    }
    cout << '\n';
}
