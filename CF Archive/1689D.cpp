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
x1 - x2 + y1 - y2 => x1 + y1 - (x2 + y2)
x1 - x2 + y2 - y1 => x1 - y1 - (x2 - y2)
x2 - x1 + y1 - y2 => x2 - y2 - (x1 - y1)
x2 - x1 + y2 - y1 => x2 + y2 - (x1 + y1)
*/

void chkmax(int& a, int b) {
    a = max(a, b);
}

void chkmin(int& a, int b) {
    a = min(a, b);
}

void solve(){
    int n, m;
    cin >> n >> m;
    V<string> g(n);
    in(g);
    int mnDiff = 1e10, mxDiff = -1e10;
    int mnSum = 1e10, mxSum = -1e10;
    rep(i, 0, n) {
        rep(j, 0, m) {
            if(g[i][j] == 'B') {
                chkmax(mxDiff, i - j);
                chkmax(mxSum, i + j);
                chkmin(mnDiff, i - j);
                chkmin(mnSum, i + j);
            }
        }
    }
    int ans = 1e10, bi = -1, bj = -1;
    rep(i, 0, n) {
        rep(j, 0, m) {
            int here = i + j - mnSum;
            chkmax(here, i - j - mnDiff);
            chkmax(here, mxDiff - (i - j));
            chkmax(here, mxSum - (i + j));
            if(here < ans) {
                ans = here;
                bi = i, bj = j;
            }
        }
    }
    cout << bi + 1 << " " << bj + 1 << '\n';
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