#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

int sum(int x) {
	int sm = 0;
	for(int l = 1, r; l <= x; l = r + 1) {
		int h = x / l;
		if(h == 0) break;
		r = x / h;
		r = min(r, x);
		sm += (r - l + 1) * h;
	}
	return sm;
}

void solve() {
	int a, b;
	while(true) {
		cin >> a >> b;
		if(a == 0 && b == 0) break;
		cout << sum(b) - sum(a - 1) << '\n';
	}
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while(t--) {
        solve();
    }
}
