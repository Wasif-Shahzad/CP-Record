#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) x.begin(), x.end()

void solve() {
	set<int> s = {2, 3, 5, 7, 11};
	int a, b;
	cin >> a >> b;
	if(s.count(a + b)) cout << "Alice\n";
	else cout << "Bob\n";
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
