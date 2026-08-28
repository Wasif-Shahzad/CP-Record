#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--) {
        int a, b;
        cin >> a >> b;
        int ans = 0, cur = 0;
        for(int i = 0; i < 30; i++) {
            cur += (1 << i);
            if(a + b < cur) break;
            int so = 0;
            for(int j = 0; j <= i; j += 2) {
                so += (1 << j);
            }
            int se = cur - so;
            if(so <= a && se <= b) ans = i + 1;
            else if(so <= b && se <= a) ans = i + 1;
            else break;
        }
        cout << ans << '\n';
    }
}
