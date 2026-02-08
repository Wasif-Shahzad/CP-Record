#include <bits/stdc++.h>
using namespace std;
#define int long long int
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define sz(a) (int)a.size()
#define V vector
#define ff first
#define ss second
#define rep(i, a, n) for (int i = a; i < n; i++)
#define rev(i, a, n) for(int i = a; i > n; i--)
#define out(a) cout << a << "\n"
#define outv(a) rep(i, 0, (int)a.size()) cout << a[i] << " "; cout << endl;
#define in(a) for(auto &i: a) cin >> i;
#define pb push_back
#define pii pair<int, int>
const int mod1 = 1e9+7, mod2 = 998244353;

/*
if ith removal is at index j
then we add
(n - j) - a[j] - (k - i)
if we take add so it becomes
n * k - sum(j + a[j]) - kC2
n * k - kC2 - sum(j + a[j])
compute j + a[j] and pick k maximums
*/

void solve(){
    int n, k;
    cin >> n >> k;
    V<int> a(n);
    in(a);
    int tot = accumulate(all(a), 0ll) + n * k - k * (k - 1) / 2;
    rep(i, 0, n) {
        a[i] = i + a[i];
    }
    sort(all(a)); reverse(all(a));
    rep(i, 0, k) tot -= a[i];
    out(tot - k);
}

signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}