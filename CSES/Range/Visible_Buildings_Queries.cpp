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
    int n, q;
    cin >> n >> q;
    V<int> a(n); in(a);
    stack<int> st;
    V<int> g(n, -1);
    int LOG = 21;
    V<V<int>> nxt(LOG, V<int>(n + 1));
    for(int i = 0; i < LOG; i++) nxt[i][n] = n;
    rev(i, n - 1, -1) {
        while(st.size() && a[st.top()] <= a[i]) st.pop();
        if(st.size()) {
            g[i] = st.top();
            nxt[0][i] = st.top();
        } else {
            nxt[0][i] = n;
        }
        st.push(i);
    }
    for(int i = 1; i < LOG; i++) {
        for(int j = n - 1; j >= 0; j--) {
            nxt[i][j] = nxt[i - 1][nxt[i - 1][j]];
        }
    }
    auto jump = [&] (int d, int v) -> int {
        for(int i = LOG - 1; i >= 0; i--) {
            if((1 << i) & d) v = nxt[i][v];
        }
        return v;
    };
    while(q--) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        int lo = 0, hi = n;
        while(hi > lo + 1) {
            int mid = (hi + lo) / 2;
            int target = jump(mid, l);
            if(target > r) hi = mid;
            else lo = mid;
        }
        cout << hi << '\n';
    }
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