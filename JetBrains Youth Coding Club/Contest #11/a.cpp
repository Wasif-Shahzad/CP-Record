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
    int n, m;
    cin >> m >> n;
    V<int> a(n);
    in(a);
    priority_queue<int> pq1(all(a));
    int mx = 0;
    for(int i = 0; i < m; i++) {
        int cur = pq1.top();
        pq1.pop();
        mx += cur;
        if(cur != 1) pq1.push(cur - 1);
    }
    priority_queue<int, vector<int>, greater<int>> pq(all(a));
    int mn = 0;
    for(int i = 0; i < m; i++) {
        int cur = pq.top();
        pq.pop();
        mn += cur;
        if(cur != 1) pq.push(cur - 1);
    }
    cout << mx << " " << mn << '\n';
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