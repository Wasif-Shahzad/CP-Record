#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

/*
n! / (r! * (n - r)!)
product (n, n - 1, n - r + 1) / r!
*/

const int mod = 1e9+7;
int power(int a, int b) {
	int res = 1;
	while(b > 0) {
		if(b & 1) res = (res * a) % mod; 
		a = a * a % mod;
		b /= 2;
	}
	return res;
}

int ncr(int n, int r) {
	int up = 1;
	for(int i = n; i > n - r; i--) up = (up * i) % mod;
	int bott = 1;
	for(int i = 1; i <= r; i++) bott = (bott * i) % mod;
	bott = power(bott, mod - 2);
	return (up * bott) % mod;
}

void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	int init = power(2, n) - 1;
	if(init < 0) init += mod;
	init -= ncr(n, a);
	if(init < 0) init %= mod, init += mod;
	init -= ncr(n, b);
	if(init < 0) init %= mod, init += mod;
	cout << init << '\n';
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
