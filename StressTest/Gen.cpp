//
// Gen.cpp
// Created by Wasif on 10/29/25 at 15:16:18.
//

#include <bits/stdc++.h>
#include <random> // Added for modern C++ random number generation
using namespace std;
#define int long long
#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Use modern C++ for random number generation
    std::mt19937 gen(std::random_device{}());

    int q = 1;
    cout << q << "\n";

    while (q--) {
        // Generate n (1 <= n <= 10)
        std::uniform_int_distribution<int> n_dist(1, 10);
        int n = n_dist(gen);
        cout << n << "\n";

        // Generate p[i] (100 <= p[i] <= 1000, p[i] % 100 == 0)
        // We can pick a random number from 1 to 10 and multiply by 100
        std::uniform_int_distribution<int> p_dist(1, 15);
        for (int i = 0; i < n; ++i) {
            cout << p_dist(gen) * 100 << (i == n - 1 ? "" : " ");
        }
        cout << "\n";

        // Generate x, a
        // 1 <= x <= 100
        // 1 <= a <= n
        // To satisfy x+y <= 100 and y >= 1, x must be at most 99.
        std::uniform_int_distribution<int> x_dist(1, 99);
        std::uniform_int_distribution<int> ab_dist(1, n);
        
        int x = x_dist(gen);
        int a = ab_dist(gen);
        cout << x << " " << a << "\n";

        // Generate y, b
        // 1 <= y <= 100, x + y <= 100 -> 1 <= y <= (100 - x)
        // 1 <= b <= n
        std::uniform_int_distribution<int> y_dist(1, 100 - x);
        int y = y_dist(gen);
        int b = ab_dist(gen);
        cout << y << " " << b << "\n";

        // Generate k (1 <= k <= 10^14)
        // For small n, a huge k is likely an "impossible" case.
        // Let's generate k in a more reasonable range for small inputs.
        // Max possible sum is n * max(p) approx 10 * 1000 = 10000.
        // Let's generate k up to 50000 to have both possible and impossible cases.
        std::uniform_int_distribution<int> k_dist(1, 50000);
        int k = k_dist(gen);
        cout << k << "\n";
    }

    return 0;
}