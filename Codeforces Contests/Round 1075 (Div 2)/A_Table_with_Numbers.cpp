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
    int n, h, w;
    cin >> n >> h >> w;
    V<int> a(n); in(a);
    sort(all(a));
    int x = 0, y = 0;
    if(h > w) swap(h, w);
    for(int i: a) {
        if(i <= h) x++;
        else if(i <= w) y++;
    }
    if(x <= y) out(x);
    else {
        int prs = y + (x - y) / 2;
        out(prs);
    }
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