// BrutePartition.cpp — brute force partition into k contiguous segments (n,k <= 8)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    if (!(cin >> n >> k)) return 0;
    vector<ll> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    if (k > n) {
        // impossible to split into k non-empty parts
        cout << "Impossible (k > n)\n";
        return 0;
    }

    ll best = LLONG_MIN;
    // There are n-1 possible cut positions (between i and i+1). Represent by bits of mask.
    int gaps = max(0, n - 1);
    int maxMask = 1 << gaps;
    for (int mask = 0; mask < maxMask; ++mask) {
        // count how many cuts this mask has
        if (__builtin_popcount((unsigned)mask) != k - 1) continue;

        ll sum = 0;
        int segL = 0;
        bool ok = true;
        for (int g = 0; g < gaps; ++g) {
            if ( (mask >> g) & 1 ) {
                // cut after index g -> segment segL..g
                int L = segL, R = g; // inclusive
                // compute value of segment [L..R]
                ll val = LLONG_MIN;
                for (int pos = L; pos <= R; ++pos) {
                    int m = pos - L + 1; // 1-based position inside segment
                    val = max(val, a[pos] + (ll)m);
                }
                sum += val;
                segL = g + 1;
            }
        }
        // handle last segment segL..n-1
        if (segL <= n-1) {
            int L = segL, R = n-1;
            ll val = LLONG_MIN;
            for (int pos = L; pos <= R; ++pos) {
                int m = pos - L + 1;
                val = max(val, a[pos] + (ll)m);
            }
            sum += val;
        } else {
            ok = false; // shouldn't happen for correct masks
        }

        if (ok) best = max(best, sum);
    }

    cout << best << "\n";
    return 0;
}
