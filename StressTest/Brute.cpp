#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin >> t;
	int n;
	cin >> n;
	vector<int> p(n);
	for(int i = 0; i < n; i++) {
		cin >> p[i];
	}
	int x, a, y, b, k;
	cin >> x >> a >> y >> b >> k;
	sort(p.begin(), p.end());
	int ans = n + 5;
	do {
		int have = 0;
		for(int i = 0; i < n; i++) {
			if((i + 1) % a == 0 && (i + 1) % b == 0) {
				have += p[i] / 100 * (x + y);
			} else if((i + 1) % a == 0) {
				have += p[i] / 100 * x;
			} else if((i + 1) % b == 0) {
				have += p[i] / 100 * y;
			}
			if(have >= k) {
				ans = min(ans, i + 1);
				break;
			}
		}
	} while(next_permutation(p.begin(), p.end()));
	if(ans > n) cout << -1 << '\n';
	else cout << ans << '\n';
}