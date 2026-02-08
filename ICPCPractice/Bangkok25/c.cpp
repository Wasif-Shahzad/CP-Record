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
    int x;
    cin >> x;
    if(x == 1) {
        out(x);
        out(x);
        return;
    }
    int n = 2, need = -1;
    while(true) {
        int here = n * (n + 1) / 2 - x;
        if(here & 1) {
            n++;
            continue;
        }
        if(here <= 2 and here != 0) {
            n++;
            continue;
        }
        if(here / 2 == n * (n + 1) / 2 - 2 || here / 2 == n * (n + 1) / 2 || here / 2 > n * (n + 1) / 2) {
            n++;
            continue;
        }
        need = here / 2;
        break;
        n++;
    }
    vector<int> sign(n + 1, 0);
    while(n > 1) {
        if(need >= n and need - n != 1) {
            sign[n] = 1;
            need -= n;
        }
        n--;
    }
    cout << sign.size() - 1 << '\n';
    cout << 1;
    for(int i = 2; i < (int)sign.size(); i++) {
        cout << (sign[i] ? "-" : "+") << i;
    }
    cout << '\n';
}

signed main(){
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(NULL);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}