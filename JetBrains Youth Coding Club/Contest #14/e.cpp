#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

void solve() {
    int n;
    cin >> n;
    const int N = 1e6;
    vector<int> cur(N + 1, 0), nxt(N + 1, 0);
    int ans = 0;
    auto solve = [&] () -> void {
        for(int i = 0; i <= N; i++) {
            if(cur[i]) {
                if(i + 1 <= N && !cur[i + 1]) {
                    ans++;
                    if(cur[i] & 1) ans++;
                    continue;
                }
                int j = i;
                while(j + 1 <= N) {
                    int rem = cur[i] & ~1; //bitwise way to write x = x - (x % 2)
                    
                }
            }
        }
    };
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while(t--) {
        solve();
    }
}
