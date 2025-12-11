// Gen.cpp — random test generator for the subsequence-split problem
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    std::mt19937 rng((unsigned) chrono::high_resolution_clock::now().time_since_epoch().count());

    int n = rng() % 8 + 1;          // 1..8
    int k = rng() % n + 1;          // 1..n

    cout << n << " " << k << "\n";

    for (int i = 0; i < n; i++) {
        int ai = rng() % 10 + 1;    // 1..10
        cout << ai << (i + 1 < n ? ' ' : '\n');
    }

    return 0;
}
