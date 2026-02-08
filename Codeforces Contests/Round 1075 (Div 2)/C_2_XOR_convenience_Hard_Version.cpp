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
c1 for odd n
power of 2 is -1
10 3 2 5 4 7 6 9 8 1 
*/

void solve(){
    int n;
    cin >> n;
    V<int> ans(n + 1);
    set<int> rem;
    for(int i = 1; i <= n; i++) rem.insert(i);
    for(int i = 3; i < n; i += 2) {
        ans[i] = i ^ 1;
        rem.erase(i ^ 1);
    }
    ans[n] = 1;
    rem.erase(1);
    for(int i = 2; i < n; i += 2) {
        ans[i] = i + 1;
        rem.erase(i + 1);
    }
    ans[1] = *rem.begin();
    bool f = false;
    if(n & 1) f = true;
    for(int i = 3; i <= n; i += 2) {
        if(f) break;
        if((ans[1] ^ i) > i && (ans[1] ^ i) <= n) {
            swap(ans[1], ans[i]);
            f = true;
            break;
        }
    }
    if(!f) {
        out(-1);
        return;
    }
    for(int i = 1; i <= n; i++) cout << ans[i] << " ";
    cout << '\n';
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