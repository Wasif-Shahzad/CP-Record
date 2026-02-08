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
    int n, x;
    cin >> n >> x;
    int our = 0;
    int bst = 0, ba = 0, bb = 0, bc = 0;
    rep(i, 0, n) {
        int a, b, c;
        cin >> a >> b >> c;
        our += (b - 1) * a;
        if(a * b - c > bst) {
            bst = a * b - c;
            ba = a, bb = b, bc = c;
        }
    }
    if(our >= x) {
        out(0);
        return;
    }
    if(bst <= 0) {
        out(-1);
        return;
    }
    int need = x - our;
    cout << (need + bst - 1) / bst << '\n';
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