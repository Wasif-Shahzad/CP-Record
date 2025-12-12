//
// Gen.cpp
// Created by Wasif on 12/12/25 at 11:52:30.
//

#include <bits/stdc++.h>
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

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
    int n = generateRandomInt(1, 8);
    int k = generateRandomInt(0, 32);
    cout << n << " " << k << '\n';
    for(int i = 0; i < n; i++) {
        cout << generateRandomInt(0, 16) << " ";
    }
    cout << '\n';
}