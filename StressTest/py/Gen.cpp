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
    // 1. Obtain a seed for the random number engine.
    // Using high_resolution_clock provides a good variable seed.
    unsigned seed = std::chrono::high_resolution_clock::now().time_since_epoch().count();

    // 2. Standard mersenne_twister_engine seeded with the current time
    // This is the random number engine.
    std::mt19937 eng(seed);

    // 3. Define the distribution for the specific range [l, r]
    // The uniform_int_distribution includes BOTH l and r in the possible output.
    std::uniform_int_distribution<int> distrib(l, r);

    // 4. Generate the random number
    return distrib(eng);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << 1 << '\n';
    cout << generateRandomInt(1, 31) << " " << generateRandomInt(1, 31) << '\n';
}