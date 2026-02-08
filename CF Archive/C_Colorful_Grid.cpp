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

void print0(int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 1; j < m; j++) {
            cout << (j & 1 ? "r " : "b ");
        }
        cout << '\n';
    }
    for(int j = 1; j < m; j++) cout << "b ";
    if(m & 1) cout << "r\n";
    else cout << "b\n";
    int cur = m & 1;
    for(int i = 2; i < n; i++) {
        cur ^= 1;
        for(int j = 1; j < m; j++) cout << "b ";
        if(cur) cout << "r\n";
        else cout << "b\n";
    }
}

void print2(int n, int m) {
    for(int i = 1; i < n; i++) {
    for(int j = 1; j < m; j++) {
        cout << (j & 1 ? "r " : "b ");
    }
    cout << '\n';
    }
    if(n & 1) {
        for(int j = 1; j < m; j++) {
            cout << (j & 1 ? "r " : "b ");
        }
        cout << '\n';
    } else {
        for(int j = 1; j < m; j++) {
            cout << (j & 1 ? "b " : "r ");
        }
        cout << '\n';
    }
    for(int i = 0; i < m; i++) {
        cout << "b ";
    }
    cout << '\n';
    for(int i = 1; i + 1 < n; i++) {
        cout << (i & 1 ? "b " : "r ");
        for(int j = 1; j < m; j++) cout << "r ";
        cout << '\n';
    }
}

void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    int d = k - (n + m - 2);
    if(d < 0 || ((d % 4) & 1)) {
        cout << "NO\n";
        return;
    } 
    cout << "YES\n";
    if(d % 4 == 0) print0(n, m);
    else print2(n, m);
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