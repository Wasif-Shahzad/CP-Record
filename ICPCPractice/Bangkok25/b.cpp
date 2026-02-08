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
    // 4 3 2 1
    // 
    int n, m;
    cin >> n >> m;
    if(n == 2) {
        if(m & 1) cout << "2 1 \n";
        else cout << "1 2 \n";
        return;
    }
    if(m >= n - 1) {
        rev(i, n, 0) cout << i << " ";
        cout << '\n';
    } else {
        rev(i, n, n - m) cout << i << " ";
        rep(i, 1, n - m + 1) cout << i << " ";
        cout << '\n';
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