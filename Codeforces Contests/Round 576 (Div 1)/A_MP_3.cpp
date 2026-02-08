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

int _log(int x) {
    int c = 0, p = 1;
    while(p < x) c++, p *= 2;
    return c;
}

void solve(){
    int n, I;
    cin >> n >> I;
    V<int> a(n);
    in(a);
    sort(all(a));
    I *= 8;
    int l = 0, r = -1;
    map<int, int> f;
    auto valid = [&] () {
        int K = sz(f);
        return n * _log(K) <= I; 
    };
    int ans = n;
    // 1 2 2 3 3 4
    for(; l < n; l++) {
        f[a[l]]++;
        while(r + 1 < l && !valid()) {
            if(f[a[r + 1]] == 1) {
                f.erase(a[r + 1]);
            }
            else f[a[r + 1]]--;
            r++;
        }
        ans = min(ans, n - (l - r));
    }
    cout << ans << '\n';
}

signed main(){
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}