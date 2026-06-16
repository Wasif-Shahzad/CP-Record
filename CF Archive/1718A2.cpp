#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

/*
only segments of length 2 or length 1 needed
if ai was smaller I could dp
[1, 2, 3, 3, 2, 1]
[0, 3, 3, 3, 2, 1] => 1
[0, 0, 0, 0, 1, 1] => 3
[0, 0, 0, 0, 0, 0] => 4 
*/

void solve() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++) {
		cin >> a[i];
	}
	map<int, int> h;
	h[0] = 1;
	int l = 0, x = 0;
	int ans = 0;
	for(int i = 0; i < n; i++) {
		x ^= a[i];
		if(h.count(x)) {
			ans += i - l;
			h.clear();
			h[x] = 1;
			l = i + 1;
		}
		h[x] = 1;
	}
	if(l != n) ans += n - l;
	cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while(t--) {
        solve();
    }
}
