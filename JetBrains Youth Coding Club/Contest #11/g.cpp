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
    string cur;
    for(int i = 0; i < 4; i++) {
        map<string, int> cnt;
        string here = cur;
        for(char x = '0'; x <= '9'; x++) {
            here += x;
            for(int j = i + 1; j < 4; j++) {
                here += '0';
            } 
            cout << here << endl;
            int c, k;
            cin >> c >> k;
            cnt[here] = c;
            here = cur;
        }
        int bst = 0;
        for(auto [v, c]: cnt) bst = max(bst, c);
        for(auto [v, c]: cnt) {
            if(c == bst) {
                cur += v[i];
                break;
            }
        }
    }
    cout << cur << endl;
}

signed main(){
    // ios_base::sync_with_stdio(NULL);
    // cin.tie(NULL);
    int t = 1;
    // cin >> t;
    while(t--){
        solve();
    }
}