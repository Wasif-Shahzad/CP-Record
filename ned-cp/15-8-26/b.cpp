#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // 2 * a + 2 * b = n
    // if a = b then 4 * a = n so if n is divisible by 4 we just decrease by 1
    // 2 * (a + b) = n
    // a + b = n / 2
    // ways = n / 4
    int n;
    cin >> n;
    if(n & 1) {
        cout << 0 << '\n';
        return 0;
    }
    int num = n / 2;
    cout << (num / 2) - (num % 2 == 0) << '\n';
}
