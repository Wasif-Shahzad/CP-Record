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

void solve(){
    int n; cin >> n;
    V<int> a(n); in(a);
    sort(all(a));
    V<int> ans;
    map<int, int> has;
    {
        rep(i, 0, n - 1) {
            if(a[i] == a[n - 1]) continue;
            if(has.count(a[n - 1] - a[i])) {
                if(has[a[n - 1] - a[i]] == 1) {
                    has.erase(a[n - 1] - a[i]);
                    continue;
                }
                has[a[n - 1] - a[i]]--;
            } else {
                has[a[i]]++;
            }
        }
        if(sz(has) == 0) {
            ans.pb(a[n - 1]);
        }
    }
    if(n % 2 == 0) {
        has.clear();
        int target = a[n - 1] + a[0];
        rep(i, 1, n - 1) {
            if(has.count(target - a[i])) {
                if(has[target - a[i]] == 1) {
                    has.erase(target - a[i]);
                    continue;
                }
                has[target - a[i]]--;
            } else {
                has[a[i]]++;
            }
        }
        if(sz(has) == 0) {
            ans.pb(target);
        }
    }
    outv(ans);
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