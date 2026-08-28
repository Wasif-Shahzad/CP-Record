#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // a[i] & a[j] >= a[i] ^ a[j] if first same set bit > first differing bit
    // if we target kth bit then we need a number <= 2^k
    // its easier to count bad pairs
    // all numbers which don't have our MSB set
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> has(31, 0);
        vector<int> a(n);
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            for(int j = 0; j < 31; j++) {
                if((1 << j) & a[i]) {
                    has[j]++;
                }
            }
        }
        int ans = n * (n - 1) / 2;
        sort(a.rbegin(), a.rend());
        for(int i = 0; i < n; i++) {
            int msb = 31 - __builtin_clz(a[i]);
            int rem = n - i - 1;
            ans -= rem - has[msb] + 1;
            for(int j = 0; j < 31; j++) {
                if((1 << j) & a[i]) has[j]--;
            }
        }

        cout << ans << '\n';
    }
}
